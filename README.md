# BankingSystem2.0
A Bank Created In C++ with cool functionalities! If you want the whole program in one file then just download **BankingSystem2p0.cpp**
# Banking System

This is a simple banking system implemented in C++. It provides basic banking functionalities such as creating account, making deposits and withdrawals, and transferring funds between accounts.
```Modified Version Of Previous Project``` **https://github.com/SharonIV0x86/BankingSystem**
## Table of Contents
- [Features](#features)
- [Logging](#Logging)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#Contributions)
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
- If the user tried to modify the balance ammount in **account.txt** the program will not allow them to do so.
- If the user tries to delete or truncuate the contents of the program files. The code will generate new ones.
- CROSS PLATFORM! Tested on Windows with GCC-x64 and MSYS2. Yet to test on Linux systems.

## Logging
   - Logs exact date and time of the action been performed in the 24hr format.
   - For easy navigation through logs you can use search following keywords in the log files
      - CREATED to find logs related to when a user(s) CREATED their account.
      - LOGGED INTO to find the logs related to when the user LOGGED into their account.
      - DEPOSITS to find logs events related to deposits in the logs.txt file.
      - WITHDRAWN to find logs events related to withdrawals in the logs.txt file.
      - WRONG CREDENTIALS (or just WRONG is enough )to find the logs related to event when a user entered their wrong credentials.
      - DELETED to find logs related to when the user deleted their account.
      - LOGGED OUT to find events related to when user logged out of their account. This can also include internal program errors hence can be inaccurate.
## Installation

**For Both Linux And Windows**
Run the Makefile using **make** make sure to have Makefile installed and if running in VS code make sure to have the Makefile extension installed and enabled.
If you dont want to use Makefile, you can directly run this **make** command in any terminal the program files will be recompiled and executed, just make sure your terminal should be opened in the same folder where the files are located.

To Delete the executable run **make delete** to delete the executable file.

**On Linux Only**
If you face any issues as the log files are empty it is possibly because the text files are missing permissions. run this command 
```chmod +rwx Bank.cpp bankDeclarations.hpp bankDefinitions.hpp color.hpp```
and then just run **make**
If the problem persists. then execute.
```chmod +rwx *```
**Make Error**
If you encounter make error of ```-lssl -lcrypto``` linking errors while running the Makefile its possibly because of the absence of the OpenSSL libraries
so, you can install those libraries by running ```sudo apt-get install libssl-dev```.


## USAGE 
- Open the terminal and run **make** to run the make file.
- Once you pass human verification then,
- You have to create your account, you will have a starting balance of **5000**.
- In the account menu you can delete your account also.
- **Output.txt** contains the pin and password in encrypted form.
- **logs.txt** contains event logs like creation, logging of accounts and all other events.
- **account.txt** contains updated balance

## Contributions
If you'd like to contribute to this project feel free so raise an issue or open a pull request.


## Future Updates
- Implementing a database for storing all the data, log events.
- Adding functionality for creating multiple users.

# BankingSystem2p0.cpp
BankingSystem2p0.cpp Is a standalone file, consisting of all function and classes definition, if you need just one file for the whole banking system, go for it. It is a bit outdated for now but will work on it.


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
**Heyy This is me SharonIV aka Jasper. I have been working on this program for a week now so i was finally able to complete this project that i started literally last year. I will be adding more and more functionalities to this code and make it even more better as i keep learning this amazing C++ language with time. I know this code that i have written is not up to the point and consists some problems and inconsistencies but i will surely try to fix everything i can. If you are reading this and want to collaborate and work on a project together then you can reach me on my discord Jasperr#6925 or jasperbrue**
