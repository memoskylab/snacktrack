# 🧾 SnackTrack – C++ Online Food Ordering System

SnackTrack is a simple terminal-based food ordering system built in C++ for our CSC404 Programming 2 project at UiTM. It allows users to register, place orders from a predefined menu, provide feedback, and generate basic reports — all using structured programming, file handling, and C++ standard features.

---

## 🎯 Project Objectives

- Practice **structured programming** using `struct`, `functions`, and arrays
- Implement **file I/O** to store and retrieve data (`customer.txt`, `order.txt`, `feedback.txt`)
- Provide a simple **menu-driven interface** for users
- Collaborate as a group using **GitHub**, **CLion**, **Visual Studio Code** and proper project management practices

---

## 📦 Features

- 👤 Register Customer (save to `customer.txt`)
- 🍽️ Place Order (select from menu, calculate total, save to `order.txt`)
- 📋 View Order Summary
- 💬 Insert Feedback (save to `feedback.txt`)
- 🗂️ View All Feedback
- 📊 Generate Report (coming soon)

---

## 💻 Technologies Used

- C++20 (CLion IDE)
- File Handling with `fstream`
- Modular code with `.cpp` / `.h` files
- Git & GitHub for version control
- Structured programming using `struct`, 1D & 2D arrays

---
## 📁 File Structure

```

SnackTrack/
│
├── .gitignore              # Git ignore rules
├── README.md               # Project documentation
│
├── data/                   # Text files to store persistent data
│   ├── customer.txt
│   ├── feedback.txt
│   ├── order.txt
│   ├── order_ID.txt
│
├── include/                # Header files for each module
│   ├── customer.h
│   ├── feedback.h
│   ├── menu.h
│   ├── order.h
│   └── report.h
│
└── src/                    # Source files for each module
    ├── customer.cpp
    ├── feedback.cpp
    ├── main.cpp            # Main entry point of the program
    ├── menu.cpp
    ├── order.cpp
    └── report.cpp
```
---

## 🚧 Current Progress

- [x] Basic main menu navigation
- [x] Register customer to file
- [x] Place order with subtotal + grand total
- [x] Save order to file
- [x] Feedback system with rating + comment
- [x] Generate Reporting

---

## 👨‍💻 Project Team

| Name                            | Role                  |
|---------------------------------|-----------------------|
| Hilmi                           | Functional            |
| Mohammad Aslam Bin Azman        | Developer             |
| Taufiq                          | Developer             |
| Khuzairi                        | QA                    |

---

## 📝 Notes

> This project is part of a university assignment. While it's designed for learning, we welcome ideas, feedback, and contributions within the team. 🚀
