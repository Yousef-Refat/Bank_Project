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
Bank_Project/
│── Bank_Project_ConsoleApp/
│   │── main.cpp                         # Entry point of the application
│   │── clsAddNewClientScreen.h          # Displaying Add New Client Screen
│   │── clsAddNewUserScreen.h            # Displaying Add New User Screen
│   │── clsBankClient.h                  # Clients class
│   │── clsClientListScreen.h            # Displaying Client list Screen
│   │── clsCurrenciesListScreen.h        # Displaying Currencies List Screen
│   │── clsCurrency.h                    # Currency class
│   │── clsCurrencyCalculatorScreen.h    # Displaying Currencies Calculator Screen
│   │── clsCurrencyExchangeMainScreen.h  # Displaying Currencies Exchange Screen
│   │── clsDate.h                        # Date reading class
│   │── clsDeleteClientScreen.h          # Displaying Delete Client Screen
│   │── clsDeleteUserScreen.h            # Displaying Delete User Screen
│   │── clsDepositScreen.h               # Displaying Deposit Screen
│   │── clsFindClientScreen.h            # Displaying Find Client Screen
│   │── clsFindCurrencyScreen.h          # Displaying Find Currency Screen
│   │── clsFindUserScreen.h              # Displaying Find User Screen
│   │── clsInputValidate.h               # Class for validating
│   │── clsListClientScreen.h            # Displaying Clients List Screen
│   │── clsListUsersScreen.h             # Displaying Users List Screen
│   │── clsLoginRegisterScreen.h         # Displaying Login Register List Screen
│   │── clsLoginScreen.h                 # Displaying Login Screen
│   │── clsMainScreen.h                  # Displaying Main Screen
│   │── clsManageUsers.h                 # Manage Users
│   │── clsManageUsersScreen.h           # Displaying Manage Users Screen          
│   │── clsPerson.h                      # Persons class
│   │── clsScreen.h                      # Global class for all screens
│   │── clsString.h                      # Class for manipulating string
│   │── clsTotalBalancesScreen.h         # Displaying Total Balances Screen
│   │── clsTransactionsScreen.h          # Displaying Transactions Screen
│   │── clsTransferLogScreen.h           # Displaying Transfer log Screen
│   │── clsTransferScreen.h              # Displaying Transfer Screen
│   │── clsUpdateClientScreen.h          # Displaying Update Currency Rate Screen
│   │── clsUpdateCurrencyRateScreen.h    # Displaying Update Currency Rate Screen
│   │── clsUpdateUserScreen.h            # Displaying Update User Screen
│   │── clsUser.h                        # users class
│   │── clsUtil.h                        # some utilities
│   │── clsWithdrawScreen.h              # Displaying withdraw screen
│   │── Global.h                         # Store global user
│   │── Clients.txt                      # Store clients
│   │── Currencies.txt                   # Store currencies
│   │── LoginRegister.txt                # Store login register
│   │── TransfersLog.txt                 # Store transfers log
│   │── Users.txt                        # Store users
│── README.md                        # Project documentation
```

## 🛠 Technologies Used

- **C++** for core development
- **File I/O** for persistent data storage
- **OOP Principles** (Encapsulation, Abstraction, and Modularity)

## 📖 How to Run

1. **Clone the Repository**
   ```sh
   git clone https://github.com/JooScript/Bank_Project.git
   cd Bank_Project
   ```
2. **Compile the Code** (Using g++)
   ```sh
   g++ main.cpp -o Bank_Project
   ```
3. **Run the Executable**
   ```sh
   ./Bank_Project
   ```

## 🎯 Why This Project Matters?

- Demonstrates **clean architecture** in **C++**.
- Encourages best practices in **modular design**.
- Ideal for learning **file handling, encapsulation, and abstraction** in a real-world scenario.

## 📜 License

This project is **open-source** and free to use under the [MIT License](LICENSE).

---

### 🌟 Happy Coding! 🚀
