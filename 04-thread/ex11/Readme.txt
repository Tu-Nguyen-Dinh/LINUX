BT11. Viết một chương trình thực hiện tạo 2 threads. Cả
hai threads này đều dùng chung một handler.
● Kiểm tra nếu là thread1 đang thực hiện thì in ra thông
điệp bất kì để xác định.
● Nếu là thread2 thì truyền vào dữ liệu kiểu struct
human được khởi tạo từ trước, với các thông tin: Họ
tên, năm sinh, sdt, quê quán. Sau đó in các thông tin
này ra màn hình.

Lưu ý:
Để lấy được thông tin của pthread hiện tại
pthrea_t tid = pthread_self();
pthread_equal(t1,t2) dùng để so sánh 2 thread_id

Quan trọng là typedef struct Person Person.