# BankingSystem2.0
A Bank Created In C++ with cool functionalities! If you want the whole program in one file then just download **BankingSystem2p0.cpp**
# Banking System

This is a simple banking system implemented in C++. It provides basic banking functionalities such as creating account, making deposits and withdrawals, and transferring funds between accounts.
```Modified Version Of Previous Project``` **https://github.com/SharonIV0x86/BankingSystem**
## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [License](#license)
- [Future Updates](#Future-Updates)
- [Working](#Working)
- [Developer's Note](#Developer's-Note)
## FEATURES!
- Withdraw Or Deposit.
- Your account credentials are protected with a simple encryption technique!
- 8 out of 10 on error handling.
- Very efficient logging technique, which will track 
   - Your withdrawals.
   - Your deposits.
   - Your new account creation.
   - Your logging into the account.
   - Your trying to delete existing account.
   - Logs exact date and time of the action been performed in the 24hr format
   - For easy navigation through logs you can use search following keywords in the log file
      - WITHDRAWN to find logs events related to withdrawals in the accountLogs.txt file
      - DEPOSITS to find logs events related to deposits in the accountLogs.txt file
      - LOGIN to find events related to who logged into which account.
      - CREATED to find event logs related to what accounts have been created
- If the user tried to modify the balance ammount in **account.txt** the program will not allow them to do so.
- If the user tries to delete or truncuate the contents of the program files. The code will generate new ones.
- CROSS PLATFORM! Tested on Windows with GCC-x64. Yet to test on Linux systems.
- 
## USAGE 
- Once you run 2main.cpp for the first time. You will have to **create** a new account. Be sure not to forget your credentials.
- Once you pass human verification then,
- You have to create your account, you will have a starting balance of **5000**.
- In the account menu you can delete your account also.
- **Output.txt** contains the pin and password in encrypted form.
- **logs.txt** contains event logs like creation, logging of accounts.
- **accountLogs.txt** contains logs of account related activities.
- **account.txt** contains updated balance
## Installation
For Windows: Download the file as Zip and extract the folder. And run **Bank.cpp** And everytime you want to use the program just run the same file.
For Linux: Git clone **https://github.com/SharonIV0x86/BankingSystem2.0#bankingsystem20** to your desired folder.
If you face any issues as the log files are being empty. run this command 
```chmod +rwx 2main.cpp 2suppliments.h```
If the problem persists. then execute.
```chmod +rwx *```
## Future Updates
all possible updates as of current knowledge are implemented.


## Working
```Start
|Flow Chart Created By Jasperr
|-- Check if required files exist
|   |-- If both files missing
|   |   |-- Generate missing files
|   |   |-- Exit program
|   |-- If output file missing
|   |   |-- Generate missing output file
|   |   |-- Exit program
|   |-- If log file missing
|   |   |-- Generate missing log file
|   |   |-- Exit program
|
|-- Perform human verification
|   |-- Display verification number
|   |-- Get user input for verification
|   |-- If verification fails
|   |   |-- Display error message
|   |   |-- Exit program
|
|-- Get user input for age, account name, password, and PIN
|-- If age is invalid or input is invalid
|   |-- Display error message
|   |-- Exit program
|
|-- Encrypt user credentials
|-- If output file is empty
|   |-- Display account creation message
|   |-- Write encrypted credentials to output file
|   |-- Save account creation logs
|   |-- Exit program
|
|-- Check user credentials
|   |-- Decrypt stored credentials
|   |-- If credentials match
|   |   |-- Display success message
|   |   |-- Access account
|   |-- If credentials do not match
|   |   |-- Display error message
|   |   |-- Save login attempt logs
|   |   |-- Exit program
|
|-- Access account options
|   |-- Display account details
|   |-- Get user choice
|   |-- Perform selected action
|   |   |-- If deposit selected
|   |   |   |-- Perform deposit verification
|   |   |   |-- If verification fails
|   |   |   |   |-- Display error message
|   |   |   |   |-- Go to deposit verification
|   |   |   |-- Perform deposit
|   |   |   |-- Update account balance
|   |   |   |-- Save deposit logs
|   |   |-- If withdrawal selected
|   |   |   |-- Perform withdrawal verification
|   |   |   |-- If verification fails
|   |   |   |   |-- Display error message
|   |   |   |   |-- Go to withdrawal verification
|   |   |   |-- Perform withdrawal
|   |   |   |-- Update account balance
|   |   |   |-- Save withdrawal logs
|   |   |-- If delete account selected
|   |   |   |-- Perform delete account verification
|   |   |   |-- If verification fails
|   |   |   |   |-- Display error message
|   |   |   |   |-- Go to delete account verification
|   |   |   |-- Delete account
|   |   |   |-- Save delete account logs
|   |   |-- If exit selected
|   |   |   |-- Display exit message
|   |   |   |-- Save exit logs
|   |   |   |-- Exit program
|   |-- Go to access account options
|
|-- Get to know something cool
|
|-- End
```
## Developer's Note
**Heyy This is me SharonIV aka Jasper. I have been working on this program for a week now so i was finally able to complete this project that i started literally last year. I will be adding more and more functionalities to this code and make it even more better as i keep learning this amazing C++ language with time. I know this code that i have written is not up to the point and consists some problems and inconsistencies but i will surely try to fix everything i can. If you are reading this and want to collaborate and work on a project together then you can reach me on my discord Jasperr#6925**
