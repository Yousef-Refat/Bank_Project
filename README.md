# Bank Management System (Console App) - C++

## 🚀 Overview
This is a simple yet efficient **Bank Management System** implemented as a console-based application in **C++**, following Object-Oriented Programming (**OOP**) principles and **Separation of Concerns (SoC)** for maintainability.

## 🔹 Key Features
✔ **OOP-Based Design** – Structured classes for `Account`, `Transaction`, and `Bank` to ensure reusable and modular code.  
✔ **Separation of Concerns** – Clearly divided logic, data handling, and UI layers for better scalability.  
✔ **File-Based Storage** – Persists account data using `.txt` files, eliminating the need for a database.  
✔ **Core Banking Operations** – Supports deposits, withdrawals, transfers, and transaction history viewing.  
✔ **Console User Interface** – A simple, interactive, text-based menu for ease of use.  
✔ **Error Handling** – Ensures valid user input and prevents invalid transactions.

## 📂 Project Structure
```
BankSystem/
│── main.cpp             # Entry point of the application
│── Account.h            # Account class definition
│── Account.cpp          # Account class implementation
│── Transaction.h        # Transaction class definition
│── Transaction.cpp      # Transaction class implementation
│── Bank.h               # Bank class definition
│── Bank.cpp             # Bank class implementation
│── DataStorage.h        # File handling for data persistence
│── DataStorage.cpp      # Implementation of file storage methods
│── README.md            # Project documentation
```

## 🛠 Technologies Used
- **C++** for core development
- **File I/O** for persistent data storage
- **OOP Principles** (Encapsulation, Abstraction, and Modularity)

## 📖 How to Run
1. **Clone the Repository**
   ```sh
   git clone https://github.com/yourusername/BankSystem.git
   cd BankSystem
   ```
2. **Compile the Code** (Using g++)
   ```sh
   g++ main.cpp Account.cpp Transaction.cpp Bank.cpp DataStorage.cpp -o BankSystem
   ```
3. **Run the Executable**
   ```sh
   ./BankSystem
   ```

## 🎯 Why This Project Matters?
- Demonstrates **clean architecture** in **C++**.
- Encourages best practices in **modular design**.
- Ideal for learning **file handling, encapsulation, and abstraction** in a real-world scenario.

## 📜 License
This project is **open-source** and free to use under the [MIT License](LICENSE).

---
### 🌟 Happy Coding! 🚀
