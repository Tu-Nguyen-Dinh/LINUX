#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "./myfifo";
    int fd;
    char buffer[50];

    // Mở FIFO để đọc dữ liệu
    fd = open(fifo_path, O_RDONLY);

    // Đọc dữ liệu
    read(fd, buffer, sizeof(buffer));
    printf("Process 2 received: %s\n", buffer);

    // Đóng file descriptor
    close(fd);

    return 0;
}
