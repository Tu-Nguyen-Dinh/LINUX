#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "./myfifo";
    int fd;

    // Tạo FIFO nếu nó chưa tồn tại
    
    mkfifo(fifo_path, 0666);

    // Mở FIFO để ghi dữ liệu
    fd = open(fifo_path, O_WRONLY);

    // Gửi dữ liệu
    char mess[100]="Hello from Process 1!";
    write(fd,mess ,sizeof(mess) );

    // Đóng file descriptor
    close(fd);

    return 0;
}
