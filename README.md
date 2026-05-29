# 🏦 Bank Management System in C++

A console-based **Bank Management System** developed using **C++**, demonstrating real-world banking operations using **Object-Oriented Programming (OOP)** concepts, **STL vectors**, and **file handling**.

The system supports both **Admin** and **User** functionalities, allowing secure account management, transactions, authentication, and persistent data storage.

This project was built to practice practical software development concepts and simulate the core functionality of a basic banking application.

---

# ✨ Features

## 👤 User Features
- 🔐 User Login System
- 💰 Deposit Money
- 💸 Withdraw Money
- 🔄 Transfer Money to Other Accounts
- 📋 View Personal Account Details

---

## 🛠️ Admin Features
- 🏦 Create New Bank Accounts
- 🔍 Search Account Using Account Number
- 📑 Display All Accounts
- 💰 Deposit to Any Account
- 💸 Withdraw from Any Account
- 🔄 Transfer Between Accounts
- 🧠 Manage Multiple Accounts Dynamically

---

# 🧩 Core Concepts Used

- Object-Oriented Programming (OOP)
- Classes and Friend Classes
- Encapsulation
- STL Vector
- File Handling (`fstream`)
- Authentication System
- Record Management
- Menu-Driven Programming
- Banking Transaction Logic

---

# 💾 Data Persistence

The project uses file handling to permanently store account data inside:

```text
ac.txt
```

Account information is automatically:
- Loaded when the program starts
- Updated when the program exits

This allows account data to persist even after closing the application.

---

# 📂 Project Structure

```text
Bank-Management-System/
│
├── bank.cpp          # Complete banking system implementation
├── ac.txt            # Stores account records permanently
└── README.md         # Project documentation
```

---

# 🚀 How to Run

## 📌 Prerequisites
- C++ Compiler (g++, clang++, MinGW, etc.)

---

## ⚙️ Compile the Program

```bash
g++ bank.cpp -o bank
```

---

## ▶️ Run the Program

### Linux / Mac
```bash
./bank
```

### Windows
```bash
bank.exe
```

---

# 🔐 Authentication System

## 👤 User Login
Users can log in using:
- Account Number
- Security PIN

---

## 🛡️ Admin Login
Admin access is protected using a password system.

Admin functionalities include:
- Creating accounts
- Managing all accounts
- Viewing account records
- Performing transactions

---

# 🧑‍💻 Functionalities

## 🏦 Account Creation
Create multiple accounts with:
- Account Number
- Name
- Initial Balance
- Security PIN

---

## 💰 Deposit System
Deposit money into accounts with validation for invalid amounts.

---

## 💸 Withdrawal System
Withdraw money while checking:
- Valid amount
- Sufficient balance

---

## 🔄 Money Transfer
Transfer money securely between accounts.

---

## 🔍 Account Search
Search and display accounts using account numbers.

---

## 📋 Display All Accounts
View all stored accounts and balances.

---

# 🛡️ Validations & Safety Rules

- ❌ Cannot withdraw more than available balance
- ❌ Negative amounts are rejected
- ❌ Invalid transfers are prevented
- ❌ Same-account transfer is not allowed
- ❌ Unauthorized login access is denied
- ✅ Secure account-based operations

---

# 🧠 Learning Outcomes

This project helped in understanding:

- Practical implementation of OOP in C++
- File handling and persistent storage
- User authentication systems
- Managing collections of objects using STL vectors
- Building menu-driven applications
- Designing banking transaction systems
- Real-world software logic and modular design

---

# 🔮 Future Improvements

- 🔒 Password Encryption
- 📜 Transaction History
- ✏️ Update Account Details
- 🗑️ Delete Account Feature
- 📊 Sorting Accounts by Balance or Name
- 📅 Account Statements
- 🖥️ GUI-Based Banking Application
- 🌐 Database Integration
- ☁️ Cloud Storage Support

---

# 🤝 Contributing

Contributions and improvements are welcome!  
Feel free to fork this project and enhance it.

---

# 📄 License

This project is created for educational and learning purposes.

---

# ⭐ Support

If you found this project useful, consider giving it a ⭐ on GitHub!
