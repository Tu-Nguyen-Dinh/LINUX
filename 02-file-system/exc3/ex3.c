#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    const char *filename ="test.txt";
    const char *data = "Hello, this is a test file! \n";

    // tạo file và mở file
    
    int fd = open(filename, O_CREAT | O_RDWR , 0777);
    if(fd == -1 )
    {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    //ghi dữ liệu vào file
    if(write(fd, data, strlen(data)) == -1)
    {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    // đóng file
    close(fd);
    //lấy thông tin về file bằng struct stat
    struct stat fileStart;
    if(stat(filename, &fileStart) == -1)
    {
        perror("Error getting file information");
        exit(EXIT_FAILURE);
    }

    //hiển thị thông tin file 

    printf("Loại file : %s \n", S_ISREG(fileStart.st_mode)? "Regular file":"not a regular file");
    printf("Tên file: %s \n",filename);
    printf("Thời gian chỉnh sửa lần cuối: %s", ctime(&fileStart.st_mtime));
    printf("Kích thước: %ld bytes\n", fileStart.st_size);
}