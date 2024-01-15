#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc, char* const argv[])
{
    pid_t process_pid = fork();
    int status, rv;
    if(process_pid == 0)
    {
        //----child process-----
        printf("My ID child process: %d\n", getpid());
        while(1);
       
    }else if(process_pid > 0)
    {
        rv = wait(&status);
        if (rv == -1)
        {
            printf("wait() unsuccessful\n");
        }
        
        printf("PID of child process: %d\n", rv);
        if (WIFEXITED(status)) 
        {
            printf("Normally termination, status=%d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) 
        {
            printf("killed by signal, value = %d\n", WTERMSIG(status));
        } 

    }else 
    {
        printf("fork() unsuccessful\n");
    }
    return  0;
}