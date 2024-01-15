#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char *data = mmap(0, 1, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    pid_t pid;
    if (data == MAP_FAILED)
    {
        printf("Creating shared memory error! \n");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    strcpy(data, "Origin messesge!");

    if (pid == 0) // tiến trình con
    {
        printf("This is in child process!\n");
        printf("child id :%d \n", getpid());
        strcat(data, " child messesge");
        printf("Data in child: %s\n", data);
        if (munmap(data, sizeof(data)) == -1)
        {
            printf("unmap failed!\n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else // process cha
    {
        printf("This is parent process\n");
        printf("Process ID is: %d\n", getpid());
        strcat(data, " parent mess");
        printf("Data in parent: %s\n", data);
        if (munmap(data, sizeof(data)) == -1)
        {
            printf("munmap fail\n");
        }
        exit(EXIT_SUCCESS);
        //  int waitStatus;
        // if(wait(&waitStatus) == -1) // wait() return -1 when error
        // {
        //     printf("wait() Unsuccessful\n");
        // }
        // else
        // {
        //     printf("Parent waits for Child process Succesfully (pid: %d)\n", pid);
        // }
    }
}