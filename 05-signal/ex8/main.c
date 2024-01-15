#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Hàm xử lý khi nhận được tín hiệu Ctrl+C (SIGINT)
void handleCtrlC(int signum)
{
    printf("Caught Ctrl+C signal. Exiting...\n");
    //exit(signum);
}

// Hàm xử lý khi nhận được tín hiệu SIGUSR1
void handleSIGUSR1(int signum)
{
    printf("Caught SIGUSR1 signal.\n");
}

// Hàm xử lý khi nhận được tín hiệu SIGUSR2
void handleSIGUSR2(int signum)
{
    printf("Caught SIGUSR2 signal.\n");
}

int main()
{
    // Đăng ký hàm xử lý cho tín hiệu Ctrl+C (SIGINT)
    signal(SIGINT, handleCtrlC);

    kill(getpid(),SIGINT);
    //  Đăng ký hàm xử lý cho tín hiệu SIGUSR1
    signal(SIGUSR1, handleSIGUSR1);
    kill(getpid(), SIGUSR1);
    // Đăng ký hàm xử lý cho tín hiệu SIGUSR2
    signal(SIGUSR2, handleSIGUSR2);
    kill(getpid(), SIGUSR2);
    // Lặp vô hạn để chương trình không kết thúc ngay lập tức
    while (1)
    {
        // Chờ các tín hiệu
    }

    return 0;
}