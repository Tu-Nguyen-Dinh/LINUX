BT15: Tạo FIFO, trao đổi dữ liệu giữa các unrelated process.


Gợi ý :

Fifo file là được coi là một file trong bộ nhớ -> nó cx có các system call : read , write, close ,..
Tạo file fifo : mkfifo (<pathname>, <permision> );

2 tiến trình :  1 đọc, 1 ghi 
Lưu ý: chỉ khi nào đọc được thì ghi mới thoát và ngược lại . Khi nào có data ở trong pipe thì 
tiến trình đọc mới có thể đọc được và khi đọc xong mới thoát 
