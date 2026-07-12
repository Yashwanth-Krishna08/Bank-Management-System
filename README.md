# 🏦 Bank Management System (C++)

A console-based **Bank Management System** developed in **C++** using **Object-Oriented Programming (OOP)**, **STL (`unordered_map`, `stack`)**, and **File Handling**.

This project simulates core banking operations with separate **User** and **Admin** modules. It provides secure account management, persistent data storage, and transaction history tracking while demonstrating practical applications of C++ programming concepts.

---

# ✨ Features

## 👤 User Module

* User Registration (Sign Up)
* Secure Login with PIN
* Deposit Money
* Withdraw Money
* Transfer Money to Another Account
* View Account Details
* View Transaction History

---

## 👨‍💼 Admin Module

* Admin Login
* Create New Accounts
* Deposit to Any Account
* Withdraw from Any Account
* Transfer Between Accounts
* View Individual Account Details
* View All Accounts
* Update Customer Name

---

# 📚 Concepts Used

* Object-Oriented Programming (OOP)
* Classes & Objects
* Friend Classes
* Constructors
* Encapsulation
* File Handling
* STL Containers
* Hash Tables
* Stack
* Menu-Driven Programming
* Input Validation

---

# 🛠️ Technologies

* **Language:** C++
* **Standard Library (STL):**

  * `unordered_map`
  * `stack`
* File Handling (`fstream`)
* Console Application

---

# 📂 Data Structures Used

## `unordered_map<int, Account>`

Stores all bank accounts.

* **Key:** Account Number
* **Value:** Account Object

### Why `unordered_map`?

* Average **O(1)** search
* Fast insertion
* Fast updates
* Efficient account retrieval

---

## `stack<Transaction>`

Maintains transaction history for the currently logged-in user.

It stores:

* Deposit
* Withdrawal
* Transfer

Transactions are displayed in **Last-In, First-Out (LIFO)** order.

---

# 💾 File Storage

The project stores data permanently using text files.

### Account Database

```text
acc.txt
```

Stores:

* Name
* Account Number
* Balance
* PIN

---

### Transaction History

Each account has its own transaction history file.

Example:

```text
1001.txt
1002.txt
1003.txt
```

Each file stores:

* Transaction Type
* Transaction Amount

---

# 📋 Project Structure

```text
Bank-Management-System/
│
├── main.cpp
├── README.md
```

---

# 🚀 Functionalities

### Account Management

* Create Account
* Login Authentication
* Update Customer Name

### Banking Operations

* Deposit Money
* Withdraw Money
* Transfer Funds

### Information

* Display Own Account
* Display Any Account (Admin)
* Display All Accounts (Admin)
* Display Transaction History

### Storage

* Load data from file
* Save updated records
* Maintain transaction history

---

# ▶️ How to Run

### Clone the repository

```bash
git clone https://github.com/your-username/Bank-Management-System.git
```

### Compile

```bash
g++ main.cpp -std=c++17 -o BankSystem
```

### Run

Windows

```bash
BankSystem.exe
```

Linux/macOS

```bash
./BankSystem
```

---

# 📖 Sample Menu

```text
1. User Sign Up
2. User Sign In
3. Admin Sign In
```

### User Menu

```text
1. Deposit
2. Withdraw
3. Transfer
4. Display Account Details
5. Display Transaction History
6. Exit
```

### Admin Menu

```text
1. Create Account
2. Deposit
3. Withdraw
4. Display Account
5. Show All Accounts
6. Transfer
7. Update Details
8. Exit
```

---

# 🎯 Learning Outcomes

This project helped me gain practical experience with:

* Designing object-oriented applications
* Using STL containers in real-world scenarios
* Efficient data storage using `unordered_map`
* Implementing transaction history using `stack`
* Managing persistent data with file handling
* Building menu-driven console applications
* Structuring larger C++ projects

---

# 🔮 Future Improvements

* Password hashing for secure authentication
* PIN update functionality
* Account deletion
* Transaction timestamps
* Transaction receipts
* Interest calculation
* Loan management
* Better input validation
* Exception handling
* Binary file storage
* Qt/QML graphical user interface
* Database integration (SQLite/MySQL)

---


# 👨‍💻 Author

**Yashwanth Krishna**

* 💻 C++ Developer
* 📚 Learning STL & Data Structures
* 🎮 Aspiring Game Developer
* 🚀 Passionate about Software Development and Creative Programming
