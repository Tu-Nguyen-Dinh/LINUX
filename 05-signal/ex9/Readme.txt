ĐỀ BÀI:
 Kiểm tra SIGINT có bị block trong process hay không.
Nếu không thực hiện block/ublock thử SIGINT



lưu ý :
1.KIỂM TRA
sigprocmask : lấy thông tin tập hợp tin hiệu đang bị block trong tiến trình
sigismember: check xem 1 tín hiệu có nằm trong danh sách bị block hay không 
2. BLOCK/UNBLOCK
sigset_t newMask : khởi tạo 1 mặt nạ mới 
sigemptyset() 
sigaddset(): add signal vào trong newMask
sigprocmask(SIG_BLOCK , , ): block signal đang có trong newMask
sigprocmask(SIS_UNBLOCK,, ): unblock signal đang có trong newMask

