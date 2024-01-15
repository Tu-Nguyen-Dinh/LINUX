#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(int argc, char* const argv[])
{
    pid_t child_pid;

    
    // câu lệnh khởi tạo chương trình con 
    child_pid = fork();
    
    if(0 == child_pid)
    {
        printf("Child Process ID: %d\n", getpid());
        printf("Parent Process ID; %d\n", getppid());

    }else
    {
        printf("Parent Proccess PID: %d\n", getpid());
    }
    return 0;

} 