#include "bankDefinitions.cpp"

int main()
{
    clearScreen();
    std::cout << "\n\n\tPlease wait we are checking for required files! " << std::endl;
    if (!fileExists("logs/output.txt") || !fileExists("logs/logs.txt") || !fileExists("logs/account.txt"))
    {
        std::cout << "\n\n\tSome program files are missing, please wait while we fix them! " << std::endl;

        !fileExists("logs/output.txt") ? (std::ofstream("logs/output.txt"),1) : (0);
        !fileExists("logs/logs.txt") ? (std::ofstream("logs/logs.txt"), 1) : (0); //using ternaries to check for files, self note: it should return a same value
        !fileExists("logs/account.txt") ? (std::ofstream("logs/account.txt"), 1) : (0);
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
        account.savingLogs(5);
        exit(0);
    }
    std::cout << "\n\n\tEncrypting Credentials! Press enter to continue ";

    if (isFileEmpty("logs/output.txt"))
    {
        clearScreen();
        std::cout << "\n\n\tYour account credentials has been modified or truncuated, your new account is NOW created. " << std::endl;
        File->writeToFile(File->accountName);
        File->writeToFile(computeHash(File->password));
        File->writeToFile(File->pin);

        File->writeToFile("\n");

        account.savingLogs(1);
        std::cout << "\n\n\tAccount created successfully! you must now log in to your account! " << std::endl;
    }
    File->hashedPassword = computeHash(File->password);
    account.checkCredentials();
    return 0;
}
