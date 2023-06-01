#include <iostream>
#include <fstream>
#include <string.h>
#include "2suppliments.h"
int main()
{
    clear_screen();
    std::cout << "\n\n\tPlease wait we are checking for required files! " << std::endl;
    std::string outputFile = "output.txt";
    std::string logFile = "logs.txt";

    bool exists1 = fileExists(outputFile);
    bool exists2 = fileExists(logFile);
    if (!exists1 && !exists2)
    {
        clear_screen();
        std::cout << "\n\n\tMultiple program files are missing! Generating then now, you may face data loss!! " << std::endl;
        std::ofstream createLogFile("logs.txt");
        std::ofstream createOutputFile("output.txt");
        std::cout << "\n\n\tYou must now try again! " << std::endl;
        exit(EXIT_FAILURE);
    }
    else if (!exists1 && exists2)
    {
        clear_screen();
        std::cout << "\n\n\tOne of the program files are missing, new file will be created but you will face data loss! " << std::endl;
        std::ofstream createOutputFile("output.txt");
        std::cout << "\n\n\tYou must now try again! " << std::endl;
        exit(EXIT_FAILURE);
    }
    else if (exists1 && !exists2)
    {
        clear_screen();
        std::cout << "\n\n\tOne of the program files are missing, new file will be created but you will face data loss! " << std::endl;
        std::ofstream createLogFile("logs.txt");
        std::cout << "\n\n\tYou must now try again! " << std::endl;
        exit(EXIT_FAILURE);
    }
    fileIO log;
    std::cout << "\n\n\tYour must complete human verification first. " << std::endl;
    human_verification("register");
    std::cout << "\n\n\tEnter your age--> ";
    std::cin >> age;
    if (age < 18 || age > 98 || std::cin.fail())
    {
        std::cout << "\n\n\tMinor case, you must be 18 to open an account! ";
        exit(EXIT_FAILURE);
    }
    std::cout << "\n\n\tEnter the account name --> ";
    std::cin.ignore();
    std::getline(std::cin, accountName);
    check_for_empty_fields(accountName);
    checkAN = accountName;
    std::cout << "\n\n\tEnter your account password--> ";
    std::getline(std::cin, password);

    check_for_empty_fields(password);
    std::cout << "\n\n\tEnter your NUMERIC PIN--> ";
    std::getline(std::cin, pin);
    check_for_empty_fields(pin);
    if (pin.length() > 4 || pin.length() < 4 ){
        std::cout << "\n\n\tPin lenght must be only of 4 characters! ";
        exit(EXIT_FAILURE);
    }
    
    int strTOint = std::stoi(pin);
    std::cout << "\n\n\tEncrypting Credentials! Press enter to continue ";

    if (isFileEmpty("output.txt"))
    {
        clear_screen();
        std::cout << "\n\n\tYour account credentials has been modified or truncuated, on the account of suspicious activity your new account is created. " << std::endl;
        encryptedAccountName = log.encrypt(accountName);
        log.writeToFile(encryptedAccountName);

        encrypted_password = log.encrypt(password);
        log.writeToFile(encrypted_password);

        log.writeToFile(pin);

        log.writeToFile("\n");

        fileIO::savingLogs(1);
        std::cout << "\n\n\tAccount created successfully! you must now log in to your account! " << std::endl;
        exit(EXIT_SUCCESS);
    }
    log.checkCredentials(accountName, password, pin);
    return 0;
}

/*                   GNU GENERAL PUBLIC LICENSE
                      Version 3, 29 June 2007

Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
Everyone is permitted to copy and distribute verbatim copies
of this license document, but changing it is not allowed.*/