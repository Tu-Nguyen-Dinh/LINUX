#include<stdio.h>
#include<unistd.h>

#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{  int fd, wr;
    const char *filename="test.txt";
    const char *data="test Append ";
     fd= open(filename,O_RDWR | O_APPEND, 0777);
    if(fd==-1)
    {
        printf("open fail");
        exit(EXIT_FAILURE);
    }
     if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("Error seeking to the beginning of the file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    wr = write(fd, data, strlen(data));
    if(wr==-1)
    { 
        perror("Error writing file ");
        close(fd);
        exit(EXIT_FAILURE);
        
    }
    /*
    với cờ O_APPEND thì con trỏ sẽ luôn đặt ở cuối file kể cả việc mình dùng lệnh lseek
    */
}