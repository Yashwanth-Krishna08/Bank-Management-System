# 🏦 Bank Management System (C++)

A console-based Bank Management System developed using **C++**, focusing on Object-Oriented Programming, STL, file handling, data management, and practical software development concepts.

This project is an ongoing learning and development project, with plans to introduce a Qt/QML graphical interface and MySQL database integration.

## 🚀 Features

### Account Management
- Create new bank accounts.
- User login and authentication.
- View account details and balance.
- Update account information.
- Search and manage accounts.

### Banking Operations
- Deposit money.
- Withdraw money.
- Transfer money between accounts.
- Validate transaction amounts and account balances.
- Roll back sender deductions if a transfer fails.

### Transaction Management
- Generate unique transaction IDs.
- Record deposits, withdrawals, and transfers.
- Maintain individual account transaction histories.
- Display transaction history in reverse chronological order.

### Security and Input Handling
- Password masking during terminal input.
- Displays `*` instead of actual password characters.
- Supports Backspace while entering passwords.
- Separate user and administrator access.

### Data Persistence
- Store account information using file handling.
- Load account records when the application starts.
- Update account data in storage.
- Maintain transaction records using separate files.

## 🛠️ Technologies Used

- **Language:** C++
- **Concepts:** OOP, Encapsulation, STL, File Handling
- **STL:** `unordered_map`, `stack`
- **Tools:** Visual Studio Code, CMake, Git, GitHub

## 📁 Project Structure

```text
BankManagementSystem/
│
├── include/
│   ├── Account.h
│   ├── Bank.h
│   └── Transaction.h
│
├── src/
│   ├── Account.cpp
│   ├── Bank.cpp
│   ├── Transaction.cpp
│   └── main.cpp
│
├── data/
│
├── CMakeLists.txt
├── .gitignore
└── README.md
```

## ⚙️ Building and Running

### Prerequisites
- C++ compiler supporting C++17 or later.
- CMake.
- Git (optional).

### Build using CMake

```bash
cmake -S . -B build
cmake --build build
```

Run the generated executable from the build directory.

## 📚 Concepts Practiced

- Object-Oriented Programming
- Classes and Objects
- Encapsulation
- Constructors and Destructors
- STL Containers
- Hash-based account lookup using `unordered_map`
- Stack-based transaction history
- File handling and data persistence
- Input validation
- Modular programming and multi-file project organization
- Password masking using character-by-character input

## 🔮 Future Improvements

- Secure password storage using password hashing.
- Administrator authentication improvements.
- Failed login attempt limits and account lockout.
- Transaction timestamps.
- Improved input validation and error handling.
- Qt/QML graphical user interface.
- MySQL database integration.

## 👨‍💻 Developer

**Yashwanth Krishna**

B.Tech Computer Science and Engineering Student

GitHub: [Yashwanth-Krishna08](https://github.com/Yashwanth-Krishna08)

---

*This project is actively being developed as part of my journey in C++ programming and software development.*
