BT12: Viết một chương trình thực hiện tạo 3 threads.
● Thread 1: Thực hiện việc nhập dữ liệu sinh viên từ bàn
phím, bao gồm thông tin: Họ tên, ngày sinh, quê quán.
● Thread2: Mỗi lần nhập xong dữ liệu một sinh viên,
thread này sẽ ghi thông tin sinh viên đó vào file (mỗi
thông tin sinh viên nằm trên 1 dòng)
thongtinsinhvien.txt.
● Thread3: Đọc dữ liệu vừa ghi được và in ra màn hình
sau đó thông báo cho thread 1 tiếp tục nhập thêm sinh
viên.


Gợi ý:
khởi tạo khóa MUTEX
pthread_mutex_t mutex;
pthread_mutex_init(&mutex,NULL);

mỗi khi vào critical sesion:
-> khóa mutex: pthread_mutex_lock(&mutex);
-> thoát mutexL pthread_mutex_unlock(&mutex);

Nhập xuất chuỗi:
fgets(data,sizeof(data),stdin);

