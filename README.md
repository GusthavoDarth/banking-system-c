# Banking System in C

A console-based banking application with account management, transactions, and persistent storage.

## Features
- Create up to 100 accounts (name, email, phone)
- Deposit and withdraw money with validation
- Update account details
- View all accounts or a specific one
- Complete transaction history per account
- Data saved to binary file (`bank.dat`)

## How to Compile and Run
```bash
gcc -o bank main.c functions.c
./bank        # Linux/macOS
bank.exe      # Windows
```
## What I Learned
- Struct manipulation and nested structs
- Binary file I/O for data persistence
- Input validation and error handling
- Code organization with multiple files and headers
