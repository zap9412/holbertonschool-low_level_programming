# C - File I/O

## General

This project introduces low-level file handling in C using **system calls**. You will learn how to open, create, read, write, and close files using POSIX functions, and understand the difference between standard library functions and system calls.

### You will learn:

- How to search for reliable information online
- How to **create**, **open**, **close**, **read**, and **write** files
- What **file descriptors** are
- The 3 standard file descriptors:
  - `STDIN_FILENO` (standard input — usually keyboard)
  - `STDOUT_FILENO` (standard output — usually terminal)
  - `STDERR_FILENO` (standard error — usually terminal)
- Their POSIX symbolic names and purpose
- How to use the system calls:
  - `open`
  - `close`
  - `read`
  - `write`
- What file permissions are and how to set them with `open`
- The meaning of the flags:
  - `O_RDONLY`
  - `O_WRONLY`
  - `O_RDWR`
  - plus others like `O_CREAT`, `O_TRUNC`, `O_APPEND`
- What a **system call** is
- Difference between a **function** and a **system call**

System calls interact directly with the kernel, while standard C functions (like `printf`) are implemented in user land and may perform additional processing.

---

## Requirements

### General

- Allowed editors: **vi**, **vim**, **emacs**
- Compilation will be done on **Ubuntu 20.04 LTS** using:

  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89
