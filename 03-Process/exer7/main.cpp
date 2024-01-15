#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void func(int signum)
{
    wait(NULL);
}

int main(int argc, char *const argv[])
{
    pid_t child_pid = fork();

    if (0 == child_pid)
    {
        printf("The id of child process = %d\n", getpid());
    }
    else
    {
        signal(SIGCHLD, func);

        printf("The id of parent process = %d\n", getpid());
        while (1)
            ;
    }
}