#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// thử tạo ra vô số luồng mà mình không free resourse cho nó (pthread_join);
int count=0;
static void* thread_handle(void *argx)
{
    //do nothing 
    
}
int main(int argc, char const *argv[])
{
    /* code */
    int ret;
    // tao 2 thread lần lượt tăng biến đếm của global_var lên

    pthread_t thread_id;
    while(1)
    {
        count++;
    if(ret = pthread_create(&thread_id, NULL, &thread_handle,NULL ))
    {
        printf("ERROR: %d\n", ret);
        break;
    }
   // pthread_join(thread_id,NULL);
    if(count%100 == 0)
    {
        printf("threadID : %d\n", count);
    }

    }
    printf("IAM back\n");
}