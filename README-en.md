# CrashZone-Freeroam

[Tiếng Việt](README.md) | English

## Introduction
CrashZone-Freeroam is a freeroam gamemode source for SA-MP/open.mp servers, designed for developers who want to build or extend GTA San Andreas server systems. The project focuses on modular architecture, maintainability, extensibility, and integration with popular plugins.

## Plugins Used
| Plugin      | Link |
|-------------|------|
| MySQL       | [github.com/pBlueG/SA-MP-MySQL](https://github.com/pBlueG/SA-MP-MySQL) |
| Streamer    | [github.com/samp-incognito/samp-streamer-plugin](https://github.com/samp-incognito/samp-streamer-plugin) |
| PawnPlus    | [github.com/IS4Code/PawnPlus](https://github.com/IS4Code/PawnPlus) |
| SAMP BCrypt | [github.com/Sreyas-Sreelal/samp-bcrypt](https://github.com/Sreyas-Sreelal/samp-bcrypt) |

## Architecture
- Source code is divided into modules: config, core, player, authentication, for clear management and easy extension.
- Player system: manages player info, login state, authentication via MySQL and BCrypt.
- Dialog: uses asynchronous dialogs for login/registration.
- Database: data operations via asynchronous functions.

## Requirements
- [open.mp Server v1.4.0.2779](https://github.com/openmultiplayer/open.mp/releases) or newer
- Required plugins (see plugins folder)
- Compile: Qawno/qawno.exe (or use vscode configuration)

## Contribution
For feedback, bug reports, or feature requests, please contact via Github or the author's email.

## Author Information
Email: letuank2018@gmail.com
