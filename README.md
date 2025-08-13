# CrashZone-Freeroam

Tiếng Việt | [English](README-en.md)

## Giới thiệu
CrashZone-Freeroam là mã nguồn gamemode Freeroam dành cho máy chủ SA-MP/open.mp, hướng tới Developer muốn xây dựng hoặc mở rộng hệ thống server GTA San Andreas. Dự án tập trung vào kiến trúc module, dễ bảo trì, dễ mở rộng và tích hợp các plugin phổ biến.

## Plugin sử dụng
| Plugin      | Link |
|-------------|------|
| MySQL       | [github.com/pBlueG/SA-MP-MySQL](https://github.com/pBlueG/SA-MP-MySQL) |
| Streamer    | [github.com/samp-incognito/samp-streamer-plugin](https://github.com/samp-incognito/samp-streamer-plugin) |
| PawnPlus    | [github.com/IS4Code/PawnPlus](https://github.com/IS4Code/PawnPlus) |
| SAMP BCrypt | [github.com/Sreyas-Sreelal/samp-bcrypt](https://github.com/Sreyas-Sreelal/samp-bcrypt) |

## Kiến trúc
- Mã nguồn chia thành các module: cấu hình, core, player, authentication, giúp quản lý rõ ràng và mở rộng dễ dàng.
- Hệ thống player: quản lý thông tin, trạng thái đăng nhập, xác thực qua MySQL và BCrypt.
- Dialog: sử dụng dialog bất đồng bộ cho đăng nhập/đăng ký.
- Database: thao tác dữ liệu qua các hàm bất đồng bộ.

## Yêu cầu
- [open.mp Server v1.4.0.2779](https://github.com/openmultiplayer/open.mp/releases) trở lên
- Các plugin cần thiết (xem thư mục plugins)
- Biên dịch: Qawno/qawno.exe (hoặc sử dụng cấu hình vscode)

## Đóng góp
Mọi ý kiến đóng góp, báo lỗi hoặc yêu cầu mở rộng vui lòng gửi qua Github hoặc email tác giả.

## Thông tin tác giả
Email: letuank2018@gmail.com