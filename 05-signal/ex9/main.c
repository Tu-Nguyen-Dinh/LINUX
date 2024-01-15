#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void checkingSignal()
{
    sigset_t currentMask;
    // Lấy tập hợp tín hiệu đang bị block
    if(sigprocmask(SIG_BLOCK, NULL, &currentMask) == -1 )
    {
        printf("Error getting signal mask\n");
        exit(EXIT_FAILURE);
    }
    // Kiểm tra xem SIGINT có bị block hay không 
    if ( sigismember(&currentMask, SIGINT))
    {
        printf("SIGINT is currently blocked \n");
    }else 
    {
        printf("SIGINT is not blocked \n");
    }
}
void blockUnblockSIGINT()
{
    sigset_t newMask;

    // tạo một tập mới không chứa SIGINT 
    sigemptyset(&newMask);
    // thêm SIGINT vào tập mới của newMask
    sigaddset(&newMask, SIGINT);

    //BLOCK SIGINT 
    if(sigprocmask(SIG_BLOCK,&newMask, NULL) == -1)
    {
        printf("ERROR blocking sigint\n");
        exit(EXIT_FAILURE);
    }
    checkingSignal();
    //UNBLOCK SIGINT
    if(sigprocmask(SIG_UNBLOCK, &newMask, NULL) == -1 )
    {
        printf("ERROR ublocking sigint\n");
        exit(EXIT_FAILURE);
    }
    checkingSignal();
}
int main()
{
    checkingSignal();
    blockUnblockSIGINT();

}
