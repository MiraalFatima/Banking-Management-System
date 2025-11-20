# 🏦 Banking Management System

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![OOP](https://img.shields.io/badge/OOP-Concepts-orange?style=for-the-badge)
![File Handling](https://img.shields.io/badge/File_Handling-fstream-blue?style=for-the-badge)

A console-based application developed in **C++** to simulate the operational workflow of a real-world bank. This project demonstrates the practical application of **Object-Oriented Programming (OOP)** principles and **File Handling** to store and retrieve customer data persistently in a single robust codebase.

## 🔑 Key Features
* **Account Management:** Create new accounts with unique account numbers.
* **Transactions:** Perform secure **Deposit** and **Withdrawal** operations.
* **Balance Inquiry:** Real-time checking of account balance.
* **Data Persistence:** Uses binary file handling (`account.dat`) to save records even after the program closes.
* **Admin Controls:** Ability to modify or close (delete) existing customer accounts.

## 🛠️ Tech Stack
* **Language:** C++ (Standard 11/17)
* **Core Concepts:** Classes & Objects, Inheritance, File Streams (`fstream`).
* **IDE:** VS Code / Dev-C++ / Visual Studio.

## 🚀 How to Run
1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/MiraalFatima/Banking-Management-System.git](https://github.com/MiraalFatima/Banking-Management-System.git)
    ```
2.  **Compile the code:**
    Since the entire project is in one file, you can compile it easily:
    ```bash
    g++ main.cpp -o banking
    ```
    *(Note: If your file is named differently, e.g., `Banking.cpp`, replace `main.cpp` with that name).*

3.  **Run the executable:**
    * On Windows: `bankingmanagement.exe`
    * On Linux/Mac: `./bankingmanagementsystem`

## 📂 Project Structure
```text
├── bankingmanagementsystem.cpp          # Contains all class logic, file handling, and main menu
                                         # Binary file created automatically to store records
└── README.md
