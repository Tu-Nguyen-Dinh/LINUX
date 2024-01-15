#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h> //chứa cấu hình cần thiết cho socket
#include <netinet/in.h> // thư viện chưa các hằng số 
#include<arpa/inet.h>
#include<unistd.h>

#define LISTEN_BACKLOG 50
#define BUFF_SIZE 256
#define handle_error(msg)

/* chức năng chat*/
void chat_func(int new_socket_fd)
{
    int numb_read, numb_write;
    char sendbuff[BUFF_SIZE];
    char recvbuff[BUFF_SIZE];
    while(1)
    {
        memset(sendbuff,'0',BUFF_SIZE);
        memset(recvbuff,'0',BUFF_SIZE);
        /*đọc dữ liệu từ socket*/
        /*hàm read sẽ block cho đén khi đọc dữ liệu*/
        numb_read = read(new_socket_fd, recvbuff, BUFF_SIZE);
        if (strncmp("exit", recvbuff, 4) == 0) {
            system("clear");
            break;
        }
        printf("\nMessage from Client: %s\n", recvbuff);
         /* Nhập phản hồi từ bàn phím */
        printf("Please respond the message : ");
        fgets(sendbuff, BUFF_SIZE, stdin);

        /* Ghi dữ liệu tới client thông qua hàm write */
        numb_write = write(new_socket_fd, sendbuff, sizeof(sendbuff));
        if (numb_write == -1)
            handle_error("write()");
        
        if (strncmp("exit", sendbuff, 4) == 0) {
            system("clear");
            break;
        }

        sleep(1);
    }
    close(new_socket_fd);
    
}
int main(int argc, char* argv[])
{
    int port_no, len, opt;
    int server_fd, new_socket_fd;
    struct sockaddr_in serv_addr, client_addr; //khởi tạo stuct địa chỉ cho client và server 
    if(argc < 2)
    {
        printf("No port provided\ncommand: ./server <port number>\n");
        exit(EXIT_FAILURE);
    }else port_no = atoi(argv[1]);
     memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    memset(&client_addr, 0, sizeof(struct sockaddr_in));

    /*create socket */
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        handle_error("socket()");
    }
    /* Ngăn lỗi : “address already in use” */
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        handle_error("setsockopt()");  
    /*khởi tạo địa chỉ cho server*/
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_no);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    /*gắn socket với địa chỉ server*/
    bind(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    /*nghe tối đa 50 kết nối trong hàng đợi*/
    listen(server_fd, LISTEN_BACKLOG);
    /* Dùng để lấy thông tin client */
	len = sizeof(client_addr);
    while(1)
    {
        printf("Server is listening at port : %d \n....\n",port_no);
        	new_socket_fd  = accept(server_fd, (struct sockaddr*)&client_addr, (socklen_t *)&len);
            	printf("Server : got connection \n");
		        chat_func(new_socket_fd);
    }
        close(server_fd);
        return 0;

}