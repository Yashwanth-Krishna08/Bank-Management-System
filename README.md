# 🏦 Bank Management System (C++)

A console-based **Bank Management System** built using **C++**, **Object-Oriented Programming (OOP)**, **STL**, and **File Handling**. This project simulates the core functionalities of a banking application, including account creation, authentication, transactions, and persistent data storage.

## 🚀 Features

### 👤 User Module

* Create a new bank account
* Secure login using account number and PIN
* Deposit money
* Withdraw money
* Transfer money to another account
* View account details
* View transaction history
* Persistent account and transaction storage using files

### 👨‍💼 Admin Module

* Secure admin login
* Create customer accounts
* Deposit money into any account
* Withdraw money from any account
* Transfer funds between accounts
* Update customer details
* Display individual account information
* Display all customer accounts

---

## 🛠️ Technologies Used

* **Language:** C++
* **Concepts:** Object-Oriented Programming (OOP)
* **STL Containers:**

  * `vector`
  * `stack`
* **File Handling**
* **Classes & Objects**
* **Constructors**
* **Friend Classes**
* **Input Validation**
* **Menu-Driven Programming**

---

## 📂 Project Structure

### Account Class

Stores customer information:

* Account Number
* Name
* Balance
* Security PIN

### Transaction Class

Stores transaction details:

* Transaction Type
* Amount

### Bank Class

Handles all banking operations:

* Account creation
* Authentication
* Deposit
* Withdrawal
* Fund transfer
* Transaction history
* File operations
* Account management

---

## 💾 Data Storage

The project stores data using text files.

### Account File

Stores:

* Customer Name
* Account Number
* Balance
* Security PIN

### Transaction History

Each account has its own transaction history file, allowing users to view previous deposits, withdrawals, and transfers.

---

## 📚 Concepts Practiced

This project helped me practice:

* Object-Oriented Programming
* STL (`vector`, `stack`)
* File Handling
* Data Validation
* Function Decomposition
* Class Design
* Menu-Driven Applications
* Basic Banking Logic

---

## ▶️ How to Run

1. Clone the repository.
2. Open the project in your preferred C++ IDE (VS Code, Code::Blocks, Visual Studio, etc.).
3. Compile using a C++17 (or later) compatible compiler.
4. Run the executable.

---

## 🔮 Future Improvements

* Replace `vector` with `map` for faster account lookup.
* Use `unordered_map` for even faster average search performance.
* Encrypt account passwords/PINs.
* Generate unique account numbers automatically.
* Add transaction timestamps.
* Add interest calculation.
* Add loan management.
* Improve file format using binary or structured storage.
* Build a GUI version using Qt.
* Connect the application to a SQL database.

---

## 🎯 Learning Outcome

This project strengthened my understanding of:

* C++ programming
* STL containers
* OOP principles
* File handling
* Problem solving
* Software design
* Building larger console applications

---

## 👨‍💻 Author

**Yashwanth Krishna**

Aspiring Software Engineer | C++ Developer | Game Development Enthusiast

---

⭐ If you found this project interesting, consider giving the repository a star!
