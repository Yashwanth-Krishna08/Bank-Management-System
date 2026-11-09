# Bank Management System

A console-based Bank Management System developed using **C++**, demonstrating object-oriented programming, STL, file handling, and modular project architecture.

The project provides basic banking operations such as account creation, deposits, withdrawals, fund transfers, and transaction history management. It is designed as a learning project to explore practical C++ software development and improve code organization.

## Features

- **Account Management**
  - Create new accounts
  - User authentication
  - View account details
  - Update account information

- **Banking Operations**
  - Deposit money
  - Withdraw money
  - Transfer funds between accounts
  - Admin-level banking operations

- **Transaction Management**
  - Generate transaction IDs
  - Maintain individual account transaction histories
  - Record deposits, withdrawals, and transfers
  - Track sender and receiver details for transfers

- **Data Persistence**
  - Store account information using file handling
  - Maintain transaction records in individual text files
  - Preserve transaction ID sequences between program executions

## Technologies Used

| Technology | Purpose |
|---|---|
| C++17 | Core programming language |
| OOP | Class-based program design |
| STL | `unordered_map`, `stack` and other utilities |
| File Handling | Persistent data storage |
| CMake | Build configuration and project compilation |
| Git & GitHub | Version control |

## Project Structure

```text
BankManagementSystem/
│
├── include/
│   ├── Account.h
│   ├── Transaction.h
│   └── Bank.h
│
├── src/
│   ├── Account.cpp
│   ├── Transaction.cpp
│   ├── Bank.cpp
│   └── main.cpp
│
├── data/
│   └── Sample data files
│
├── CMakeLists.txt
├── .gitignore
└── README.md
```

### Architecture

The project follows a modular structure by separating class declarations and implementations.

- **Account:** Manages account information and balance-related operations.
- **Transaction:** Represents transaction details, including transaction IDs, types, amounts, and account references.
- **Bank:** Coordinates account management, banking operations, transaction history, and file handling.
- **main.cpp:** Provides the application entry point.

## Getting Started

### Prerequisites

Make sure you have the following installed:

- A C++17-compatible compiler (GCC or MSVC)
- CMake 3.16 or later
- Git

### Clone the Repository

```bash
git clone <YOUR_REPOSITORY_URL>
cd BankManagementSystem
```

### Configure the Project

```bash
cmake -S . -B build
```

### Build the Project

```bash
cmake --build build
```

### Run the Application

**Windows (GCC/MinGW):**

```bash
.\build\BankManagementSystem.exe
```

**Linux:**

```bash
./build/BankManagementSystem
```

*Note: The executable location may vary depending on the compiler and CMake build configuration.*

## Concepts Practiced

This project has provided practical experience with:

- Object-Oriented Programming and encapsulation
- Constructors and function overloading
- STL containers and data structures
- File input/output operations
- Multi-file C++ development
- Header files and source file separation
- Compilation and linking
- CMake-based build configuration
- Basic transaction management and rollback logic

## Future Improvements

- Improve input validation and error handling
- Strengthen transaction consistency and reliability
- Implement secure password hashing
- Improve data storage and persistence
- Introduce a database using MySQL
- Develop a graphical interface using Qt Quick / QML
- Refine the application architecture and separate storage responsibilities

## Disclaimer

This project is developed for educational purposes and is not intended for real-world banking or financial transactions. It does not implement the security, auditing, or reliability requirements of production banking systems.

## Author

**Yashwanth Krishna**

- GitHub: [@Yashwanth-Krishna08](https://github.com/Yashwanth-Krishna08)

---

*Built as a practical C++ learning project, with continuous improvements in software design and development.*
