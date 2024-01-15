#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{

    int pipe_fd[2];
    int pid;
    char buffer[100];

    if(pipe(pipe_fd) == -1)
    {
        printf("pipe creation failed!");
        exit(EXIT_FAILURE);
    }
    // tạo process con 
    pid = fork(); 

    if(pid == 0) // process con 
    {
        close(pipe_fd[0]); // đóng đầu đọc của process con 
        char data[50] = "tu dep trai ok!!!";
        write(pipe_fd[1], data,sizeof(data));
        close(pipe_fd[1]); // đóng đầu đọc của pipe
    }else 
    {
        close(pipe_fd[1]); // đóng đầu gi của process cha 
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Parent process received : %s \n", buffer);
        close(pipe_fd[0]);
    }
    return 0;

}