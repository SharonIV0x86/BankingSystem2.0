#include "bankDeclarations.h"

bool fileExists(const std::string &filename)
{
    std::ifstream file(filename);
    return file.good();
}

void clearScreen()
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

int fileIO::writeIntToFile(int value)
{
    std::ofstream createAccountFile("logs/account.txt");
    if (!fileExists("logs/account.txt"))
    {
        clearScreen();
        std::cout << "\n\n\tProgram file is missing! Generating new one, data loss! " << std::endl;
        std::cout << "\n\n\tYou must now try again! " << std::endl;
        std::ofstream createAccountFile("logs/account.txt");
        createAccountFile << 5000;
    }
    std::string filename = "logs/account.txt";
    std::ofstream file(filename);
    if (!file)
    {
        std::cout << "Error opening the file: " << filename << std::endl;
        return 1;
    }

    file << value;
    return 0;
    file.close();

    return 0;
}

void fileIO::cool()
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

    if (!fileExists("logs/account.txt"))
    {
        clearScreen();
        std::cout << "\n\n\tProgram file is missing! Generating new one, ;) " << std::endl;
        std::ofstream createAccountFile("logs/account.txt");
        createAccountFile << 5000;
        std::cout << "\n\n\tYou must now try again! " << std::endl;
    }
    std::ifstream readInt("logs/account.txt");
    readInt >> File->remainingBalance;
    readInt.close();
    return 0;
}
std::string computeHash(const std::string &input)
{
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();

    const EVP_MD *md = EVP_sha512();

    EVP_DigestInit_ex(mdctx, md, nullptr);

    EVP_DigestUpdate(mdctx, input.c_str(), input.length());

    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digestLength;

    EVP_DigestFinal_ex(mdctx, digest, &digestLength);

    EVP_MD_CTX_free(mdctx);

    std::string hash;

    for (unsigned int i = 0; i < digestLength; i++)
    {
        char buf[3];
        sprintf(buf, "%02x", digest[i]);
        hash += buf;
    }
    return hash;
}

void checkForEmptyField(std::string field)
{
    if (field.empty())
    {
        std::cout << "\n\n\tthis field cannot be empty father." << std::endl;
        exit(0);
    }
}
void humanVerification()
{
    static int count = 0;
    if (count > 3)
    {

        std::cout << "\n\n\tYou have reached the maximum number of wrong attempts! Kindly try again later.\n";
        account.savingLogs(5);
        exit(0);
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int num1 = std::rand() % 20;
    int num2 = std::rand() % 20;

    int result = num1 + num2;

    std::cout << "\n\t\t|--------------------------------------------|"
              << "\n\t\t|                                            |"
              << "\n\t\t| VERIFICATION EQUATION -----> " << num1 << " + " << num2 << "\t     |"
              << "\n\t\t|Enter the EQUATION on the screen:           |"
              << "\n\t\t|--------------------------------------------|\n";

    std::cout << "~~~~~~~~~~~~~~~~> ";

    int userInput;
    std::cin >> userInput;

    if (std::cin.fail() || result != userInput)
    {
        std::cin.clear();
        std::cout << "\n\n\tPlease enter the result of the above equation correctly!\n";
        std::cout << "\n\n\tYou have " << 3 - count << " attempts left! \n";
        count += 1;
        humanVerification();
    }
    else
    {
        clearScreen();
        std::cout << "\n\n\tVerification successful!\n";
    }
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

void Account::accountAccess()
{
    if (File->readIntFromFile() > 1000000 || isFileEmpty("logs/account.txt") || !fileExists("logs/account.txt") || File->remainingBalance < 5000)
    {
        std::cout << "\n\n\tDont be greedy bru ;) " << std::endl;
        File->writeIntToFile(5000);
        File->readIntFromFile();
    }

    std::cin.ignore();
    std::cout << "\n\n\tWELCOME TO Cyprus National Bank, " << File->permanentAccountName << "\tYour Balance--> " << File->remainingBalance
              << "\n\n\tPress 1 to DEPOSIT money to your account "
              << "\n\n\tPress 2 to WITHDRAW money from your account "
              << "\n\n\tPress 3 to DELETE current account "
              << "\n\n\tPress 4 to read bank's policies "
              << "\n\n\tPress 5 to exit and get to know something cool! "
              << "\n\n\tNote: Your account can hold max of 10,00,000!"
              << "\n\t\t---------> ";
    int choice = 0;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        clearScreen();
        std::cout << "\n\n\tTo DEPOSIT money to your account you must complete verification! " << std::endl;
        humanVerification();

        while (true)
        {
            std::cout << "\n\n\tYour current remainingBalance---> " << File->remainingBalance << std::endl;
            std::cout << "\n\n\tEnter the amount of money you want to DEPOSIT to your account. you cannot DEPOSIT more than 1,00,000 at a time!---> ";
            std::cin >> File->depositAmount;
            if (File->depositAmount > 100000 || File->depositAmount < 5000 || File->depositAmount <= 0)
            {

                std::cout << "\n\t1.) You cannot deposit more than 1,00,000 at a time. "
                          << "\n\t2.) Minimum amount for a deposit must be greater than 5,000. You have to deposit more than 5,000. "
                          << "\n\t3.) Your account can hold a maximum amount of 10,00,000 (1Million). "
                          << "\n\n\tRead Cyprus National Bank's policies. Press enter to continue " << std::endl;
                std::cin.get();
                std::cin.get();
            }

            else
            {
                break;
            }
        }
        File->remainingBalance = File->depositAmount + File->remainingBalance;
        File->writeIntToFile(File->remainingBalance);
        std::cout << "\n\n\tMoney DEPOSIT Succesful! Press enter to continue! " << std::endl;
        std::cin.get();
        savingLogs(3);
        accountAccess();
        break;
    }
    case 2:
    {
        clearScreen();
        std::cout << "\n\n\tTo WITHDRAW money to your account you must complete verification! " << std::endl;
        humanVerification();

        while (true)
        {
            clearScreen();
            std::cout << "\n\n\tYour current remainingBalance---> " << File->remainingBalance << std::endl;
            std::cout << "\n\n\tEnter the amount of MONEY you want to WITHDRAW. Entered amount must NOT be greater than your current remainingBalance!---> ";
            std::cin >> File->withdrawAmount;
            int rem = File->remainingBalance - File->withdrawAmount;
            if (rem < 5000 || File->remainingBalance <= 5000 || File->withdrawAmount > File->remainingBalance || File->withdrawAmount <= 0)
            {
                std::cout << "\n\t1.) You cannot withdraw money more than your current remainingBalance. "
                          << "\n\t2.) You cannot use the withdrawal system if your current remainingBalance is found to be 5,000 you must have remainingBalance more than 5,000 in order to withdraw. "
                          << "\n\t3.) You cannot withdrawal an amount which can make your account remainingBalance become less than 5,000."
                          << "\n\n\tYou have entered an invalid amount for WITHDRAWING, Please read Cyprus National Bank's policies. Press enter to continue. ";
                std::cin.get();
                std::cin.get();
            }
            else
            {
                break;
            }
        }
        File->remainingBalance = File->remainingBalance - File->withdrawAmount;
        std::cout << "\n\n\tMoney has been WITHDRAWN SUCCESSFULLY! " << std::endl;
        File->writeIntToFile(File->remainingBalance);
        savingLogs(4);
        accountAccess();
        break;
    }
    case 3:
    {
        std::ifstream readData("logs/output.txt");
        clearScreen();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\n\n\tWARNING, YOUR ACCOUNT DATA WILL BE DELETED FOREVER! ";

        std::cout << "\n\n\tEnter the account name --> ";
        std::getline(std::cin, File->accountName);
        checkForEmptyField(File->accountName);

        std::cout << "\n\n\tEnter your account password--> ";
        std::getline(std::cin, File->password);
        checkForEmptyField(File->password);

        std::cout << "\n\n\tEnter your PIN--> ";
        std::getline(std::cin, File->pin);
        checkForEmptyField(File->pin);

        File->permanentAccountName = File->accountName;
        File->hashedPassword = computeHash(File->password);
        File->pin = File->pin;
        if (File->permanentAccountName == File->readAcn && File->hashedPassword == File->readPassword && File->pin == File->readPin)
        {
            clearScreen();

            constexpr const char *filenames[4] = {"logs/output.txt", "logs/logs.txt", "logs/accountlogs.txt", "logs/account.txt"};

            for (int i = 0; i < 4; i++)
            {

                std::ofstream ofs(filenames[i], std::ios::trunc);
                ofs.close();
            }
            std::cout << "\n\n\t YOUR ACCOUNT HAS BEEN DELETED PERMANENTYL! " << std::endl;
            savingLogs(6);
            exit(0);
        }
        else if (File->permanentAccountName != File->readAcn && File->hashedPassword != File->readPassword && File->pin != File->readPin)
        {
            clearScreen();
            std::cout << "\n\n\tCredentials Dont match  " << std::endl;
            accountAccess();
        }
        break;
    }

    case 4:
    {
        clearScreen();
        std::cout << "\n\n\t\t\t\tDEPOSITS "
                  << "\n\t1.) You cannot deposit more than 1,00,000 at a time. "
                  << "\n\t2.) Minimum amount for a deposit must be greater than 5,000. You have to deposit more than 5,000. "
                  << "\n\t3.) Your account can hold a maximum amount of 10,00,000 (1Million). ";

        std::cout << "\n\n\t\t\t\tWITHDRAWALS "
                  << "\n\t1.) You cannot withdraw money more than your current remainingBalance. "
                  << "\n\t2.) You cannot use the withdrawal system if your current remainingBalance is found to be 5,000 you must have remainingBalance more than 5,000 in order to withdraw. "
                  << "\n\t3.) You cannot withdrawal an amount which can make your account remainingBalance become less than 5,000. For example if you have a remainingBalance of 10,000 you cannot withdraw 8,000. ";
        std::cout << "\n\n\t\t\t\tACCOUNT DELETION "
                  << "\n\tThis is a serious case, if you delete your account then you will LOST ACCESS to it FOREVER! Tread Carefully. ";

        std::cout << "\n\n\t\t\t\tIMPORTANT! "
                  << "\n\tOn the account of suspicious activity Bank holds the right and authority to reset your account remainingBalance to 5,000 or even delete your bank account "
                  << "\n\tIf you are using Cyprus National Bank's services then you are agreeing to these policies ."
                  << "\n\n\tPress enter to continue. "
                  << "\n\t\t\t\t\t\t\t~Cyprus National Bank"
                  << "\n\t\t\t\t\t\t\t~JasperrBru ";
        std::cin.get();
        accountAccess();
        break;
    }

    case 5:
    {
        break;
    }
    default:
    {
        std::cout << "\n\n\tPlease enter a valid choice! ";
        break;
    }
    }
}
void Account ::savingLogs(int logAction)
{
    std::ofstream log("logs/logs.txt", std::ios::app);
    std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    char timeString[100];
    std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));
    std::ofstream moneyLogs("logs/accountlogs.txt", std::ios::app);
    switch (logAction)
    {
    case 1:
        log << timeString << " User Named : " << File->permanentAccountName << " [+][+]CREATED an account! \n";
        break;
    case 2:
        log << "\n\n "<< timeString << " User: " << File->permanentAccountName << " LOGGED INTO[+]  their account \n";
        break;
    case 3:
        log << timeString << " User Named: " << File->permanentAccountName << " DEPOSITED[+][+] " << File->depositAmount << " NEW BALANCE " << File->remainingBalance << " \n";
        break;
    case 4:
        log << timeString << " User Named: " << File->permanentAccountName << " WITHDRAWN[-][-] " << File->withdrawAmount << " remaining remainingBalance " << File->remainingBalance << " \n";
        break;
    case 5:
        log << timeString << "User Named " << File->permanentAccountName << " tried logging into their account with WRONG CREDENTIALS[x][x] \n";
        break;
    case 6:
        log << timeString << " User Named: " << File->permanentAccountName << " DELETED their account. \n";
        break;
    case 7:
        log << timeString << " User Named: " << File->permanentAccountName << " LOGGED OUT of their account\n\n";

    default:
        break;
    }
    log.close();
    moneyLogs.close();
}
void Account::checkCredentials()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::ifstream readData("logs/output.txt");
    readData >> File->readAcn >> File->readPassword >> File->readPin;

    if (File->permanentAccountName == File->readAcn && File->hashedPassword == File->readPassword && File->pin == File->readPin)
    {
        clearScreen();
        std::cout << "\n\n\tRedirecting to your account now! Press Enter! " << std::endl;
        account.savingLogs(2);

        accountAccess();
    }
    else if (File->permanentAccountName != File->readAcn || File->hashedPassword != File->readPassword || File->pin != File->readPin)
    {
        clearScreen();
        std::cout << "\n\n\tCredentials Dont match kindly retry! This event will be recorded! " << std::endl;
        savingLogs(5);
        exit(0);
    }
}