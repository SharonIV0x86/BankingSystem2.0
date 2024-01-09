#include "bankDefinitions.cpp"

int main()
{
    clearScreen();
    printColoredText("\n\n\tPlease wait we are checking for required files! \n", ANSI_COLOR_GREEN);
    if (!fileExists("logs/output.txt") || !fileExists("logs/logs.txt") || !fileExists("logs/account.txt"))
    {
        printColoredText("\n\n\tSome program files are missing, please wait while we fix them! \n", ANSI_COLOR_RED);
        !fileExists("logs/output.txt") ? (std::ofstream("logs/output.txt"),1) : (0);
        !fileExists("logs/logs.txt") ? (std::ofstream("logs/logs.txt"), 1) : (0); //using ternaries to check for files, self note: it should return a same value
        !fileExists("logs/account.txt") ? (std::ofstream("logs/account.txt"), 1) : (0);
    }
    printColoredText("\n\n\tYour must complete human verification first. \n", ANSI_COLOR_BLUE);
    humanVerification();
    printColoredText("\n\n\tEnter your age--> ", ANSI_COLOR_CYAN);
    std::cin >> File->age;
    if (File->age < 18 || File->age > 98 || std::cin.fail())
    {
        printColoredText("\n\n\tYou must be 18 to open an account! ", ANSI_COLOR_RED);
        exit(0);
    }
    printColoredText("\n\n\tEnter the account name --> ", ANSI_COLOR_CYAN);
    std::cin.ignore();
    std::getline(std::cin, File->accountName);
    checkForEmptyField(File->accountName);
    File->permanentAccountName = File->accountName;
    printColoredText( "\n\n\tEnter your account password--> ", ANSI_COLOR_CYAN);
    std::getline(std::cin, File->password);
    checkForEmptyField(File->password);
    printColoredText( "\n\n\tEnter your NUMERIC PIN--> ", ANSI_COLOR_CYAN);
    std::getline(std::cin, File->pin);
    checkForEmptyField(File->pin);
    if (File->pin.length() > 4 || File->pin.length() < 4)
    {
        printColoredText("\n\n\tPin lenght must be only of 4 characters! ", ANSI_COLOR_RED);
        account.savingLogs(5);
        exit(0);
    }
    printColoredText( "\n\n\tEncrypting Credentials! Press enter to continue ", ANSI_COLOR_GREEN);
    if (isFileEmpty("logs/output.txt"))
    {
        clearScreen();
        printColoredText("\n\n\tYour account credentials has been modified or truncuated, your new account is NOW created. \n", ANSI_COLOR_YELLOW);
        File->writeToFile(File->accountName);
        File->writeToFile(computeHash(File->password));
        File->writeToFile(File->pin);

        File->writeToFile("\n");

        account.savingLogs(1);
        printColoredText("\n\n\tAccount created successfully! you must now log in to your account! \n", ANSI_COLOR_GREEN);
    }
    File->hashedPassword = computeHash(File->password);
    account.checkCredentials();
    return 0;
}
