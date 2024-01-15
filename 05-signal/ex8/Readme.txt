ĐỀ BÀI:
Viết chương trình in ra thông điệp bất kì khi nhấn tổ
hợp phím Ctrl+C. Đăng ký action cho SIGUSR1 và
SIGUSR2.

Sử dụng hàm signal(int signum, void * handler)

lưu ý:
signal kill không thể bị catch được 
cách kill 1 tiến trình khi đã bị ghi đè SIGINT :
ps -aux | grep exam
kill -9 pid


