# Lịch sử cập nhật

## Phiên bản 0.1.0 - 16/08/2025
### Tính năng mới
- **Hệ thống xác thực**
  - Giao diện đăng ký/đăng nhập trực quan
  - Mã hóa mật khẩu BCrypt bất đồng bộ
  - Giới hạn số lần đăng nhập sai (3 lần)

- **Hệ thống nhân vật**
  - Tạo và tùy biến nhân vật
  - Lưu trữ thông tin vào cơ sở dữ liệu

- **Quản lý dữ liệu người dùng**
  - Lưu/tải tự động (Save/Load)
  - Truy vấn MySQL bất đồng bộ
  - Xử lý truy vấn với chuỗi động

- **Hệ thống nhà**
  - Dynamic House cơ bản

### Cải tiến kỹ thuật
- Hỗ trợ tham số chuỗi động cho `__ShowMessage()`
- Thay thế pp-dialogs bằng tdialogs
- Sử dụng YSI Malloc cho bộ nhớ động
- Cấu trúc lại các module

---