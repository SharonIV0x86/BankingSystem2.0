#include <iostream>
#include <chrono>
#include <cstdio>
#include <ctime>
static int encryptionKey = 123;

std::string testPass, testAccount, testPin;

int age;

int transc1, transc2, balance;

std::string pin;
std::string encrypted_pin;
std::string decrypted_pin;
std::string mainpin;

bool accesStatus = false;

std::string accountName;
std::string encryptedAccountName;
std::string decryptedAccountName;

std::string password;
std::string encrypted_password;
std::string decrypted_password;
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
class fileIO
{
public:
    static void savingLogs(int logAction);
    void accountAccess();
    int writeIntToFile(int value)
    {
        std::ofstream createAccountFile("account.txt");
        if (!fileExists("account.txt"))
        {
            clear_screen();
            std::cout << "\n\n\tProgram file is missing! Generating new one, you may face data loss! " << std::endl;

            std::cout << "\n\n\tYou must now try again! " << std::endl;
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
    void get_to_know_something_cool();
    ~fileIO()
    {
        get_to_know_something_cool();
    };
    int readIntFromFile()
    {

        if (!fileExists("account.txt"))
        {
            clear_screen();
            std::cout << "\n\n\tProgram file is missing! Generating new one, you may face data loss! " << std::endl;
            std::cout << "\n\n\tYou must now try again! " << std::endl;
            exit(EXIT_FAILURE);
        }

        std::ifstream readInt("account.txt");
        readInt >> balance;
        readInt.close();
    }
    void writeToFile(const auto &val)
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

    std::string encrypt(std::string str)
    {
        int i, x;

        for (i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] + 2;

        return str;
    }
    std::string decrypt(std::string str)
    {
        int i, x;
        for (i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] - 2; 

        decrypted_password = str;
        return str;
    }
    void checkCredentials(std::string &ACN, std::string &pwd, std::string &PiN);
};

void human_verification(std::string secret = "none") 
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
void fileIO ::savingLogs(int logAction)
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
        moneyLogs << "\n\n\t[+] User Named " << checkAN << " DEPOSITED " << transc1 << " on " << timeString << " remaining balance " << balance << std::endl;
    }
    if (logAction == 4)
    {
        moneyLogs << "\n\n\t[-] User Named " << checkAN << " WITHDRAWN " << transc2 << " on " << timeString << " remaining balance " << balance << std::endl;
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
fileIO f;

void fileIO::checkCredentials(std::string &ACN, std::string &pwd, std::string &PiN)
{
    testAccount = ACN;
    testPass = pwd;
    testPin = PiN;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::ifstream readData("output.txt");
    std::getline(readData, accountName);
    std::getline(readData, password);
    std::getline(readData, pin);
    decryptedAccountName = decrypt(accountName);
    decrypted_password = decrypt(password);
    decrypted_pin = pin;
    if (testAccount == decryptedAccountName && testPass == decrypted_password && testPin == decrypted_pin)
    {
        clear_screen();
        std::cout << "\n\n\tRedirecting to your account now! Press Enter! " << std::endl;
        fileIO::savingLogs(2);
        accountAccess();
    }
    else if (testAccount != decryptedAccountName || testPass != decrypted_password || testPin != decrypted_pin)
    {
        clear_screen();
        std::cout << "\n\n\tCredentials Dont match kindly retry! This event will be recorded! " << std::endl;
        savingLogs(5);
        exit(EXIT_SUCCESS);
    }
}
void fileIO::get_to_know_something_cool()
{
    // clear_screen();
    std::cout << "\n\n\tThis program was created by SharonIV0x86 aka Jasperr" << std::endl
              << "\tA lot of efforts have been put into and this time i rewrote whole code from scratch after an year!" << std::endl
              << "\tStill there are some weak points in the code and it looks very complex" << std::endl
              << "\tand its also very unoptimized, yes i suck at coding swy :( lol Thanks! " << std::endl
              << "\tIf the program exitted unexpectedly is possible you entered some wrong value or contact developer ;) " << std::endl
              << "\thttps://GitHub.com/SharonIV0X86";
}

void fileIO::accountAccess()
{
Brue:
    if (readIntFromFile() > 1000000 || isFileEmpty("account.txt"))
    {
        clear_screen();
        std::cout << "\n\n\tDont be greedy bru ;) " << std::endl;
        writeIntToFile(5000);
        readIntFromFile();
    }

    std::cin.ignore();
    std::cout << "\n\n\tWELCOME " << decryptedAccountName << "\tYour Balance--> " << balance
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
        std::cout << "\n\n\tYour current balance---> " << balance << std::endl;
        std::cout << "\n\n\tEnter the amount of money you want to DEPOSIT to your account. you cannot DEPOSIT more than 1,00,000 at a time!---> ";
        std::cin >> transc1;
        if (transc1 > 100000 || transc1 < 5000 || transc1 <= 0)
        {
            std::cout << "\n\n\tMinimum You can DEPOSIT must be greater than 5000 and maximum must not be greater than 1,00,0000! " << std::endl;
            goto bru1;
        }
        balance = transc1 + balance;
        writeIntToFile(balance);
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
        if (balance <= 5000)
        {
            std::cout << "\n\n\tUpon WITHDRAWING any MONEY, your balance becomes less than 5,000 which is below the minimum balance." << std::endl;
            std::cout << "\n\n\tKinly DEPOSIT some MONEY to your account first! Press enter to continue!  " << std::endl;
            std::cin.get();
            accountAccess();
        }
        std::cout << "\n\n\tYour current balance---> " << balance << std::endl;
        std::cout << "\n\n\tEnter the amount of MONEY you want to WITHDRAW. Entered amount must not be greater than your current balance!---> ";
        std::cin >> transc2;
        if (balance - transc1 < 5000)
        {
            std::cout << "\n\n\tUpon WITHDRAWING " << transc2 << " your account balance become less than 5,000 which is not permitted! as per CYPRUS BANK INTERNATIONAL POLICIES! " << std::endl;
        }

        if (transc2 > balance || transc2 <= 0)
        {
            std::cout << "\n\n\tEntered AMOUNT must be less than your current balance! " << std::endl;
            goto bru3;
        }
        balance = balance - transc2;
        clear_screen();
        std::cout << "\n\n\tMoney has been WITHDRAWN SUCCESSFULLY! " << std::endl;
        writeIntToFile(balance);
        savingLogs(4);
        accountAccess();
        break;
    }
    case 3:
        savingLogs(6);
        clear_screen();
        std::cout << "\n\n\tEnter the account name --> ";
        std::cin.ignore();

        std::getline(std::cin, testAccount);
        check_for_empty_fields(testAccount);

        std::cout << "\n\n\tEnter your account password--> ";
        std::getline(std::cin, testPass);

        check_for_empty_fields(testPass);
        std::cout << "\n\n\tEnter your PIN--> ";
        std::getline(std::cin, testPin);
        check_for_empty_fields(testPin);
        if (testAccount == decryptedAccountName && testPass == decrypted_password && testPin == decrypted_pin)
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
        else if (testAccount != decryptedAccountName || testPass != decrypted_password || testPin != decrypted_pin)
        {
            clear_screen();
            std::cout << "\n\n\tCredentials Dont match  " << std::endl;
            exit(EXIT_SUCCESS);
        }
        accountAccess();
    case 4:
    {
        get_to_know_something_cool();
        break;
    }
    default:
        break;
    }
}
/*                   GNU GENERAL PUBLIC LICENSE
                      Version 3, 29 June 2007

Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
Everyone is permitted to copy and distribute verbatim copies
of this license document, but changing it is not allowed.*/