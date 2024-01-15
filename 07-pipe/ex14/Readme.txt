BT14: Tạo Pipe, trao đổi dữ liệu giữa các related process.

Gợi ý:
Khởi tạo pipe:
int pipe_fd[2];
pipe(pipe_fd);
Sử dụng fork(), để tạo ra process con 
process con và process cha sẽ giao tiếp với nhau thông qua IPC-Pipe

Tiến trình con :
close(pipe_fd[0]) // đóng đầu đọc của tiến trình con
write()// ghi
close đầu ghi của tiến trình con 

Tiến trình cha:
close đầu ghi
//đọc dữ liệu 
write(pipe_fd[1], buffer, sizeof(buffer));
close đầu ghi 

