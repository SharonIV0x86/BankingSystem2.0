#include "BankHeaders.cpp"

int main()
{
    clearScreen();
    std::cout << "\n\n\tPlease wait we are checking for required files! " << std::endl;
    std::string outputFile = "logs/output.txt";
    std::string logFile = "logs/logs.txt";

    bool exists1 = fileExists(outputFile);
    bool exists2 = fileExists(logFile);
    if (!exists1 && !exists2)
    {
        clearScreen();
        std::cout << "\n\n\tMultiple program files are missing! Generating now, ;) " << std::endl;
        std::ofstream createLogFile("logs/logs.txt");
        std::ofstream createOutputFile("logs/output.txt");
        std::cout << "\n\n\tYou must now try again! " << std::endl;
        return 0;
    }
    else if (!exists1 && exists2)
    {
        clearScreen();
        std::cout << "\n\n\tOne of the program files are missing, new file will be created ;)" << std::endl;
        std::ofstream createOutputFile("logs/output.txt");
        std::cout << "\n\n\tYou must now try again! " << std::endl;
        return 0;
    }
    else if (exists1 && !exists2)
    {
        clearScreen();
        std::cout << "\n\n\tOne of the program files are missing, new file will be created ;)" << std::endl;
        std::ofstream createLogFile("logs/logs.txt");
        std::cout << "\n\n\tYou must now try again! " << std::endl;
        return 0;
    }
    std::cout << "\n\n\tYour must complete human verification first. " << std::endl;
    humanVerification();
    std::cout << "\n\n\tEnter your age--> ";
    std::cin >> File->age;
    if (File->age < 18 || File->age > 98 || std::cin.fail())
    {
        std::cout << "\n\n\tYou must be 18 to open an account! ";
        exit(0);
    }
    std::cout << "\n\n\tEnter the account name --> ";
    std::cin.ignore();
    std::getline(std::cin, File->accountName);
    checkForEmptyField(File->accountName);
    File->permanentAccountName = File->accountName;
    std::cout << "\n\n\tEnter your account password--> ";
    std::getline(std::cin, File->password);

    checkForEmptyField(File->password);
    std::cout << "\n\n\tEnter your NUMERIC PIN--> ";
    std::getline(std::cin, File->pin);
    checkForEmptyField(File->pin);
    if (File->pin.length() > 4 || File->pin.length() < 4)
    {
        std::cout << "\n\n\tPin lenght must be only of 4 characters! ";
        exit(0);
    }

    int strTOint = std::stoi(File->pin);
    std::cout << "\n\n\tEncrypting Credentials! Press enter to continue ";

    if (isFileEmpty("logs/output.txt"))
    {
        clearScreen();
        std::cout << "\n\n\tYour account credentials has been modified or truncuated, your new account is NOW created. " << std::endl;
        File->writeToFile(hash(File->accountName));
        File->writeToFile(hash(File->password));
        File->writeToFile(hash(File->pin));

        File->writeToFile("\n");

        account.savingLogs(1);
        std::cout << "\n\n\tAccount created successfully! you must now log in to your account! " << std::endl;
        exit(0);
    }

    File->hashedAccountName = hash(File->accountName);
    File->hashedPassword = hash(File->password);
    File->hashedPin = hash(File->pin);
    account.checkCredentials();
    return 0;
}
