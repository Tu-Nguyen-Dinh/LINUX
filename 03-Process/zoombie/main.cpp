#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main(int argc, char* const argv[])
{
    pid_t child_pid ;
    int status;
    child_pid = fork();
    if (0 == child_pid)
    {
        /*process child*/
        printf("My ID of child process = %d\n", getpid());
        exit(EXIT_SUCCESS);

    }else 
    {
        
        wait(NULL);
        while(1);
    }
}