#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <time.h>
#define FILE "text.txt"
pthread_mutex_t mutex;
pthread_t thread_id1, thread_id2, thread_id3;

typedef struct Person
{
    char Name[20];
    int YofBirth;
    char PhoneNumber[20];
    char BirthPlace[20];
} Person;
void *input_data_handler(void *x)
{
    pthread_mutex_lock(&mutex);

    Person *data = (Person *)(x);
    printf("this is in thread1 ! \n");
    printf("input your name: \n");
    fgets(data->Name, sizeof(data->Name), stdin);
    printf("input year of birth: \n");
    char year[20];
    fgets(year, sizeof(year), stdin);
    data->YofBirth = atoi(year);

    printf("input your phone num: \n");
    fgets(data->PhoneNumber, sizeof(data->PhoneNumber), stdin);
    printf("input your home: \n");
    fgets(data->BirthPlace, sizeof(data->BirthPlace), stdin);
    pthread_mutex_unlock(&mutex);
}
void *output_data_handler(void *x)
{
    pthread_mutex_lock(&mutex);
    Person *data = (Person *)(x);
    printf("this is in thread 2! \n");
    printf("Name: %s\n", data->Name);
    printf("Year of birth: %d\n", data->YofBirth);
    printf("Home: %s\n", data->BirthPlace);
    printf("Number Phone: %s\n", data->PhoneNumber);
    pthread_mutex_unlock(&mutex);
}
void *write_into_file(void *x)
{
    pthread_mutex_lock(&mutex);
    pthread_t ctid = pthread_self();
    printf("This is thread 3 ID: %d\n", ctid);
    Person *data = (Person *)(x);
    int fd = open(FILE, O_CREAT | O_RDWR, 0777);
    write(fd, data->Name, strlen(data->Name));
    write(fd, data->BirthPlace, strlen(data->BirthPlace));
    write(fd, data->YofBirth, strlen(data->YofBirth));
    write(fd, data->PhoneNumber, strlen(data->PhoneNumber));
    close(fd);

    pthread_mutex_unlock(&mutex);
}

int main(int argc, char *argv[])
{
    if (pthread_mutex_init(&mutex, NULL) != 0)
    {
        fprintf(stderr, "Failed to initialize mutex\n");
        return EXIT_FAILURE;
    }
    Person personINF;

    pthread_create(&thread_id1, NULL, &input_data_handler, &personINF);
    pthread_create(&thread_id2, NULL, &output_data_handler, &personINF);
    pthread_create(&thread_id3, NULL, &write_into_file, &personINF);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);
}