# Aujiz-Base-Gamemode

Tiếng Việt | [English](README-en.md)

## Giới thiệu
Aujiz Base Gamemode là mã nguồn gamemode dành cho máy chủ open.mp, hướng tới nhà phát triển muốn xây dựng hoặc mở rộng hệ thống máy chủ Open Multiplayer. Dự án tập trung vào kiến trúc module, dễ bảo trì, dễ mở rộng và tích hợp các plugin phổ biến.

## Xem trước
<p>
<img src="images/img_1.png" alt="img_1" width="30%" />
<img src="images/img_2.png" alt="img_2" width="30%" />
<img src="images/img_3.png" alt="img_3" width="30%" />
</p>

## Plugin sử dụng
| Plugin      | Link |
|-------------|------|
| MySQL       | [github.com/pBlueG/SA-MP-MySQL](https://github.com/pBlueG/SA-MP-MySQL) |
| Streamer    | [github.com/samp-incognito/samp-streamer-plugin](https://github.com/samp-incognito/samp-streamer-plugin) |
| PawnPlus    | [github.com/IS4Code/PawnPlus](https://github.com/IS4Code/PawnPlus) |
| SAMP BCrypt | [github.com/Sreyas-Sreelal/samp-bcrypt](https://github.com/Sreyas-Sreelal/samp-bcrypt) |
| CrashDetect | [github.com/AmyrAhmady/samp-plugin-crashdetect](https://github.com/AmyrAhmady/samp-plugin-crashdetect) |
| sscanf | [github.com/Y-Less/sscanf](https://github.com/Y-Less/sscanf) |
| Pawn.CMD | [github.com/katursis/Pawn.CMD](https://github.com/katursis/Pawn.CMD) |

## Kiến trúc

- Mã nguồn được xây dựng với PawnPlus, tận dụng bất đồng bộ (async) và mảng động giúp tối ưu hiệu năng và mở rộng linh hoạt.
- Lưu trữ và truy vấn dữ liệu thông qua MySQL, đảm bảo tốc độ và độ tin cậy cho hệ thống.
- Mã hoá mật khẩu người dùng bằng Bcrypt, tăng cường bảo mật tài khoản.
- Kiến trúc module rõ ràng: cấu hình, core, player, authentication, dễ bảo trì và phát triển thêm tính năng mới.
- Hệ thống dialog sử dụng bất đồng bộ, nâng cao trải nghiệm người dùng khi đăng nhập/đăng ký.
- Quản lý trạng thái và thông tin người chơi theo chuẩn hiện đại, dễ tích hợp các hệ thống phụ trợ.
- Dễ dàng mở rộng, tích hợp plugin hoặc module mới cho các nhu cầu riêng của server.

## Yêu cầu
- [open.mp Server v1.4.0.2779](https://github.com/openmultiplayer/open.mp/releases) trở lên
- Các plugin cần thiết (xem thư mục plugins)

## Đóng góp
Mọi ý kiến đóng góp, báo lỗi hoặc yêu cầu mở rộng vui lòng gửi qua Github hoặc email tác giả.

## Thông tin tác giả
Email: letuank2018@gmail.com