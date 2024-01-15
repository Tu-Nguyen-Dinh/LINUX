#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <time.h>

pthread_t thread_id1, thread_id2;
typedef struct human
{
    char *hoten;
    int namsinh;
    char *sdt;
    char *quequan;
} human;

void *thread_handler(void *argx)
{
    pthread_t tid = pthread_self();
    human *data = (human *)(argx);
    if (pthread_equal(tid, thread_id1))
    {
        printf("I am in thread1\n");
    }
    if (pthread_equal(tid, thread_id2))
    {
        printf("INFOR:\n -year of birth: %d\n -name: %s\n -home: %s\n -PhoneNumber: %s\n", data->namsinh, data->hoten, data->quequan, data->sdt);
    }
}
int main(int argc, char *argv[])
{
    human Tu;
    Tu.hoten = "Nguyen Dinh Tu";
    Tu.namsinh = 2003;
    Tu.sdt = "0975608109";
    Tu.quequan = "HaNoi";

    pthread_create(&thread_id1, NULL, &thread_handler, NULL);
    pthread_create(&thread_id2, NULL, &thread_handler, &Tu);
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
}