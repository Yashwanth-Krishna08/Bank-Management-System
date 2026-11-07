# Bank Management System

A console-based Bank Management System developed using **C++**, focusing on Object-Oriented Programming, STL, file handling, and transaction management.

This project is an ongoing learning project where I'm exploring software development concepts by building and improving a practical application.

## Features

- **Account Management**
  - Create new bank accounts.
  - User login with account number and security PIN.
  - Update account details.
  - Display individual and all account details.

- **Banking Operations**
  - Deposit money.
  - Withdraw money with balance validation.
  - Transfer money between accounts.
  - Basic rollback mechanism for failed transfers.

- **Transaction Management**
  - Maintain transaction history.
  - Store transaction records in separate text files.
  - Display previous transactions.

- **Data Persistence**
  - Store account information in text files.
  - Load account details when the application starts.
  - Update stored account information when the application exits.

## Technologies Used

- **Language:** C++
- **Concepts:** OOP, Encapsulation, STL, File Handling
- **STL Containers:** `unordered_map`, `stack`
- **Libraries:** iostream, string, fstream, unordered_map, stack

## Project Structure

```text
Bank-Management-System/
│
├── main.cpp
├── acc.txt
├── [account_number].txt
└── README.md
```

- `main.cpp` – Contains the application logic and class implementations.
- `acc.txt` – Stores account information.
- `[account_number].txt` – Stores transaction history for individual accounts.

## How to Run

1. Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/Bank-Management-System.git
```

2. Navigate to the project directory:

```bash
cd Bank-Management-System
```

3. Compile the program:

```bash
g++ -std=c++17 main.cpp -o bank
```

4. Run the application:

```bash
./bank
```

On Windows:

```bash
bank.exe
```

## Concepts Practiced

- Object-Oriented Programming
- Classes and Objects
- Encapsulation
- Constructors and Member Functions
- STL Containers (`unordered_map`, `stack`)
- File Input/Output
- Conditional Statements and Loops
- Basic Transaction Rollback

## Future Improvements

- Improve transaction management with unique transaction IDs and timestamps.
- Strengthen file handling and error management.
- Improve input validation.
- Implement secure password storage.
- Separate the project into multiple header and source files.
- Integrate a Qt/QML graphical user interface.
- Explore database integration using MySQL.

## Disclaimer

This project is developed for educational purposes and is not intended for real-world banking operations. It currently uses basic file-based storage and does not implement production-grade security.

## Author

**Yashwanth Krishna**

- GitHub: [Yashwanth-Krishna08](https://github.com/Yashwanth-Krishna08)

---

*Built with C++ while learning and exploring software development.*
