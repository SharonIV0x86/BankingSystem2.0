#include <iostream>
#include <chrono>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <fstream>

constexpr int cntr = 0;
class fileIO;
class fileIO
{
public:
    int age;

    int depositAmount, withdrawAmount, remainingBalance;
    std::size_t hashedAccountName, hashedPassword, hashedPin, readAcn, readPassword, readPin;

    std::string permanentAccountName, pin, accountName, password;

    int writeIntToFile(int value);
    void cool();
    int readIntFromFile();
    template <typename Temp>
    void fileIO::writeToFile(const Temp &val)
{
    std::ofstream outputFile("logs/output.txt", std::ios::app);
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
    friend std::size_t hash(std::string hash);
};
fileIO *File = new fileIO();
class User
{
public:
    friend void checkForEmptyField(std::string field);
    friend void humanVerification();

    friend bool fileExists(const std::string &filename);
    friend bool isFileEmpty(const std::string &filename);
};
class Account
{
public:
    friend void clearScreen();
    void accountAccess();

    void savingLogs(int LogAction);

    void checkCredentials();
};
Account account;
