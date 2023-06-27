#include <iostream>
#include <chrono>
#include <cstdio>
#include <fstream>
#include <ctime>
#include "2suppliments.h"

fileIO File;
User user;
Account account;
bool fileExists(const std::string &filename)
{
    std::ifstream file(filename);
    return file.good();
}
void clear_screen()
{
#ifdef _WIN32
    {

        std::system("cls");
    }
#else
    {
        std::system("clear");
    }
#endif
}
bool isFileEmpty(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cout << "Error opening the file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            return false;
        }
    }
    return true;
}
void human_verification()
{
    int static count = 0;
    if (count >= 3)
    {
        clear_screen();
        std::cout << "\n\n\tToo many wrong attempts! " << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string alphabets_uppercase = "ABCDEFGHIJKLMNOPQRS12345678abcdefghijklmnopqrstuvwxyz910TUVWXYZ";
    int random_number_for_string = (rand() % 58);
    int random_number = rand() % 9999;
    std::string verify = std::to_string(random_number) + alphabets_uppercase[random_number_for_string] + alphabets_uppercase[random_number_for_string] + alphabets_uppercase[random_number_for_string] + std::to_string(random_number);
    std::string input;
    std::cin.ignore();
    std::cout << "\n\t\t|--------------------------------------------|"
              << "\n\t\t|                                            |"
              << "\n\t\t|VERIFICATION NUMBER----->  " << verify << "\t     |"
              << "\n\t\t|Enter the number on screen for verification:|"
              << "\n\t\t|--------------------------------------------|" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~>";

    std::getline(std::cin, input);

    if (input.empty() || input != verify)
    {

        std::cout << "\n\n\tBAD_INPUT_ retry!" << std::endl;
        count = count + 1;
        human_verification();
    }

    clear_screen();
    std::cout << "\n\n\tVERIFICATION SUCCESS!" << std::endl;
    std::cout << "\n\n\tRemember Your Credentials :) " << std::endl;
}
void check_for_empty_fields(std::string field)
{
    if (field.empty())
    {
        std::cout << "\n\n\tthis field cannot be empty father." << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::string checkAN;
void Account ::savingLogs(int logAction)
{
    std::ofstream log("logs.txt", std::ios::app);
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::string timeString = std::ctime(&currentTime);
    std::ofstream moneyLogs("accountLogs.txt", std::ios::app);
    if (logAction == 1)
    {
        log << "\n\n\t[++] User Named " << checkAN << " CREATED an account! On " << timeString << std::endl;
    }
    if (logAction == 2)
    {
        log << "\n\n\t[+] User Named " << checkAN << " LOGGED into account on " << timeString << std::endl;
    }
    if (logAction == 3)
    {
        moneyLogs << "\n\n\t[+] User Named " << checkAN << " DEPOSITED "
                  << " on " << timeString << " remaining balance " << File.balance << std::endl;
    }
    if (logAction == 4)
    {
        moneyLogs << "\n\n\t[-] User Named " << checkAN << " WITHDRAWN " << File.transc2 << " on " << timeString << " remaining balance " << File.balance << std::endl;
    }
    if (logAction == 5)
    {
        log << "\n\n\t[+ -]User Named " << checkAN << " TRIED LOGGING INTO THE ACCOUNT WITH WRONG CREDENTIALS!! " << timeString << std::endl;
    }
    if (logAction == 6)
    {
        moneyLogs << "\n\n\t[--]User Named " << checkAN << " DELETED their account on " << timeString << std::endl;
    }
}

void Account::checkCredentials()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::ifstream readData("output.txt");
    readData >> File.readAcn >> File.readPassword >> File.readPin;
    if (File.hashedAccountName == File.readAcn && File.hashedPassword == File.readPassword && File.hashedPin == File.readPin)
    {
        clear_screen();
        std::cout << "\n\n\tRedirecting to your account now! Press Enter! " << std::endl;
        account.savingLogs(2);
        accountAccess();
    }
    else if (File.hashedAccountName != File.readAcn || File.hashedPassword != File.readPassword || File.hashedPin != File.readPin)
    {
        clear_screen();
        std::cout << "\n\n\tCredentials Dont match kindly retry! This event will be recorded! " << std::endl;
        savingLogs(5);
        exit(EXIT_SUCCESS);
    }
}
void fileIO::get_to_know_something_cool()
{
    std::cout << "\n\n\tThis program was created by SharonIV0x86 aka Jasperr" << std::endl
              << "\tA lot of efforts have been put into and this time i rewrote whole code from scratch after an year!" << std::endl
              << "\tStill there are some weak points in the code and it looks very complex" << std::endl
              << "\tand its also very unoptimized, yes i suck at coding swy :( lol Thanks! " << std::endl
              << "\tIf the program exitted unexpectedly is possible you entered some wrong value or contact developer ;) " << std::endl
              << "\thttps://GitHub.com/SharonIV0X86";
}
int fileIO::readIntFromFile()
{

    if (!fileExists("account.txt"))
    {
        clear_screen();
        std::cout << "\n\n\tProgram file is missing! Generating new one, you may face data loss! " << std::endl;
        std::ofstream createAccountFile("account.txt");
        createAccountFile << 5000;
        std::cout << "\n\n\tYou must now try again! " << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ifstream readInt("account.txt");
    readInt >> File.balance;
    readInt.close();
}
int fileIO::writeIntToFile(int value)
{
    std::ofstream createAccountFile("account.txt");
    if (!fileExists("account.txt"))
    {
        clear_screen();
        std::cout << "\n\n\tProgram file is missing! Generating new one, you may face data loss! " << std::endl;
        std::cout << "\n\n\tYou must now try again! " << std::endl;
        std::ofstream createAccountFile("account.txt");
        createAccountFile << 5000;
        exit(EXIT_FAILURE);
    }
    std::string filename = "account.txt";
    std::ofstream file(filename);
    if (!file)
    {
        std::cout << "Error opening the file: " << filename << std::endl;
        return 1;
    }

    file << value;
    return 0;
    file.close();
}
void fileIO::writeToFile(const auto &val)
{
    std::ofstream outputFile("output.txt", std::ios::app);
    if (outputFile.is_open())
    {
        outputFile << val << std::endl;
        outputFile.close();
    }
    else
    {
        std::cout << "Failed to open the file for writing." << std::endl;
    }
}
void Account::accountAccess()
{
Brue:

    if (File.readIntFromFile() > 1000000 || isFileEmpty("account.txt") || !fileExists("account.txt"))
    {
        clear_screen();
        std::cout << "\n\n\tDont be greedy bru ;) " << std::endl;
        File.writeIntToFile(5000);
        File.readIntFromFile();
    }

    std::cin.ignore();
    std::cout << "\n\n\tWELCOME " << File.accountName << "\tYour Balance--> " << File.balance
              << "\n\n\tPress 1 to DEPOSIT money to your account "
              << "\n\n\tPress 2 to WITHDRAW money from your account "
              << "\n\n\tPress 3 to DELETE current account "
              << "\n\n\tPress 4 to exist and get to know something cool! "
              << "\n\n\tNote: Your account can hold max of 10,00,000!"
              << "\n\t\t---------> ";
    int choice = 0;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        clear_screen();
        std::cout << "\n\n\tTo DEPOSIT money to your account you must complete verification! " << std::endl;
        human_verification();
        clear_screen();
    bru1:
        std::cout << "\n\n\tYour current balance---> " << File.balance << std::endl;
        std::cout << "\n\n\tEnter the amount of money you want to DEPOSIT to your account. you cannot DEPOSIT more than 1,00,000 at a time!---> ";
        std::cin >> File.transc1;
        if (File.transc1 > 100000 || File.transc1 < 5000 || File.transc1 <= 0)
        {
            std::cout << "\n\n\tMinimum You can DEPOSIT must be greater than 5000 and maximum must not be greater than 1,00,0000! " << std::endl;
            goto bru1;
        }
        File.balance = File.transc1 + File.balance;
        File.writeIntToFile(File.balance);
        std::cout << "\n\n\tMoney DEPOSIT Succesful! Press enter to continue! " << std::endl;
        std::cin.get();
        savingLogs(3);
        accountAccess();
        break;
    }
    case 2:
    {
        clear_screen();
        std::cout << "\n\n\tTo WITHDRAW money to your account you must complete verification! " << std::endl;
        human_verification();
        clear_screen();
    bru3:
        if (File.balance <= 5000)
        {
            std::cout << "\n\n\tUpon WITHDRAWING any MONEY, your balance becomes less than 5,000 which is below the minimum balance." << std::endl;
            std::cout << "\n\n\tKinly DEPOSIT some MONEY to your account first! Press enter to continue!  " << std::endl;
            std::cin.get();
            accountAccess();
        }
        std::cout << "\n\n\tYour current balance---> " << File.balance << std::endl;
        std::cout << "\n\n\tEnter the amount of MONEY you want to WITHDRAW. Entered amount must not be greater than your current balance!---> ";
        std::cin >> File.transc2;
        if (File.balance - File.transc1 < 5000)
        {
            std::cout << "\n\n\tUpon WITHDRAWING " << File.transc2 << " your account balance become less than 5,000 which is not permitted! as per CYPRUS BANK INTERNATIONAL POLICIES! " << std::endl;
        }

        if (File.transc2 > File.balance || File.transc2 <= 0)
        {
            std::cout << "\n\n\tEntered AMOUNT must be less than your current balance! " << std::endl;
            goto bru3;
        }
        File.balance = File.balance - File.transc2;
        clear_screen();
        std::cout << "\n\n\tMoney has been WITHDRAWN SUCCESSFULLY! " << std::endl;
        File.writeIntToFile(File.balance);
        savingLogs(4);
        accountAccess();
        break;
    }
    case 3:
        savingLogs(6);
        clear_screen();
        std::cout << "\n\n\tEnter the account name --> ";
        std::cin.ignore();

        std::getline(std::cin, File.testAccount);
        check_for_empty_fields(File.testAccount);

        std::cout << "\n\n\tEnter your account password--> ";
        std::getline(std::cin, File.testPass);

        check_for_empty_fields(File.testPass);
        std::cout << "\n\n\tEnter your PIN--> ";
        std::getline(std::cin, File.testPin);
        check_for_empty_fields(File.testPin);
        if (File.hashedAccountName == File.readAcn && File.hashedPassword == File.readPassword && File.hashedPin == File.readPin)
        {
            clear_screen();
            const char *filenames[4] = {"output.txt", "logs.txt", "accountLogs.txt", "account.txt"};

            for (int i = 0; i < 4; i++)
            {
                std::remove(filenames[i]);
                std::cout << "\n\tPROGRAM files removed successfully! !";
            }
            std::cout << "\n\n\t YOUR ACCOUNT HAS BEEN DELETED PERMANENTYL! " << std::endl;
            exit(EXIT_SUCCESS);
        }
        else if (File.hashedAccountName == File.readAcn && File.hashedPassword == File.readPassword && File.hashedPin == File.readPin)
        {
            clear_screen();
            std::cout << "\n\n\tCredentials Dont match  " << std::endl;
            exit(EXIT_SUCCESS);
        }
        accountAccess();
    case 4:
    {
        File.get_to_know_something_cool();
        break;
    }
    default:
        break;
    }
}
std::size_t hash(std::string hash)
{
    std::hash<std::string> hasher;

    std::string salt = "0x945GHxxJsxper";
    std::string input = hash + salt;
    std::size_t hashValue = hasher(input);

    return hashValue;
}
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
    std::cout << "\n\n\tYour must complete human verification first. " << std::endl;
    human_verification();
    std::cout << "\n\n\tEnter your age--> ";
    std::cin >> File.age;
    if (File.age < 18 || File.age > 98 || std::cin.fail())
    {
        std::cout << "\n\n\tMinor case, you must be 18 to open an account! ";
        exit(EXIT_FAILURE);
    }
    std::cout << "\n\n\tEnter the account name --> ";
    std::cin.ignore();
    std::getline(std::cin, File.accountName);
    check_for_empty_fields(File.accountName);
    checkAN = File.accountName;
    std::cout << "\n\n\tEnter your account password--> ";
    std::getline(std::cin, File.password);

    check_for_empty_fields(File.password);
    std::cout << "\n\n\tEnter your NUMERIC PIN--> ";
    std::getline(std::cin, File.pin);
    check_for_empty_fields(File.pin);
    if (File.pin.length() > 4 || File.pin.length() < 4)
    {
        std::cout << "\n\n\tPin lenght must be only of 4 characters! ";
        exit(EXIT_FAILURE);
    }

    int strTOint = std::stoi(File.pin);
    std::cout << "\n\n\tEncrypting Credentials! Press enter to continue ";

    if (isFileEmpty("output.txt"))
    {
        clear_screen();
        std::cout << "\n\n\tYour account credentials has been modified or truncuated, on the account of suspicious activity your new account is created. " << std::endl;
        File.writeToFile(hash(File.accountName));
        File.writeToFile(hash(File.password));
        File.writeToFile(hash(File.pin));

        File.writeToFile("\n");

        account.savingLogs(1);
        std::cout << "\n\n\tAccount created successfully! you must now log in to your account! " << std::endl;
        exit(EXIT_SUCCESS);
    }

    File.hashedAccountName = hash(File.accountName);
    File.hashedPassword = hash(File.password);
    File.hashedPin = hash(File.pin);
    account.checkCredentials();
    return 0;
}
/*                    GNU GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007

 Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.*/