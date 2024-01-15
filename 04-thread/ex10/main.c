#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <time.h>

int cnt = 0;
void *thread_handler(int maxcount)
{
    const char *filename = "text.txt";
    const char *data = "A \n";

    // tạo file và mở file
    int fd = open(filename, O_CREAT | O_RDWR, 0777);
    printf("Performing write operation...\n");
    for (int i = 0; i <= maxcount; i++)
    {
        write(fd, data, strlen(data));
       
    }
    printf("Write opetation completed! \n");
    close(fd);
}
int main(int argc, char *argv[])
{
    // kiểm tra biến môi trường
    int option;
    if (argc != 2)
    {
        printf("Not valid argument !! \n");
        exit(1);
    }
    else
    {
        option = atoi(argv[1]);
        printf("Option is : %d\n", option);
    }
    

    // 1 thì chạy single thread
    // 2 thì chạy 2 thread
    if (option == 1)
    {   clock_t start = clock();
        int res;
        pthread_t thread_id1;
        if (res = pthread_create(&thread_id1, NULL, &thread_handler, (int *)(1000000)))
        {
            printf("Error creating thread ! \n ");
            exit(EXIT_FAILURE);
        }
        pthread_join(thread_id1, NULL);

        clock_t end = clock();
        double time_cpu_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time when using single thread: %f \n", time_cpu_used);
    }
    else
    {   int res;
        clock_t start = clock();
        pthread_t thread_id1, thread_id2;
        if (res = pthread_create(&thread_id1, NULL, &thread_handler, (int *)(500000)))
        {
            printf("Error creating thread! \n");
            exit(1);
        }
        if (res = pthread_create(&thread_id2, NULL, &thread_handler, (int *)(500000)))
        {
            printf("Error creating thread! \n");
            exit(1);
        }
        // đợi cho 2 luồng được xử lý xong 
        pthread_join(thread_id1, NULL);
        pthread_join(thread_id2, NULL);

        clock_t end = clock();
        double time_cpu_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time when using double thread: %f \n", time_cpu_used);
    }
}