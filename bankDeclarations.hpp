#include <iostream>
#include <chrono>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <format>
#include <random>
#include <memory>
#include "./lib/openssl/evp.h"
#include "./lib/openssl/rand.h"
#include "color.hpp"
class fileIO
{
public:
    int age;
    int depositAmount;
    int withdrawAmount;
    int remainingBalance;
    std::string readAcn;
    std::string readPin;
    std::string hashedPassword;
    std::string readPassword;
    std::string permanentAccountName;
    std::string pin;
    std::string accountName;
    std::string password;
    int writeIntToFile(int value) const;
    void cool() const;
    int readIntFromFile() const;
    template <typename Temp>
    void writeToFile(const Temp &val) const {
        std::ofstream outputFile("logs/output.txt", std::ios::app);
        if (outputFile.is_open())
        {
            outputFile << val << std::endl;
            outputFile.close();
        }
        else
        {
            printColoredText("\n\n\tFailed to open file for writing! \n", ANSI_COLOR_RED);
        }
    }
    ~fileIO()
    {
        cool();
    }
};
const std::unique_ptr<fileIO> File = std::make_unique<fileIO>();
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

    void savingLogs(int LogAction) const;

    void checkCredentials();
    ~Account()
    {
        savingLogs(7);
    }
};
Account account;
