#include <iostream>
// ANSI escape codes for text colors
constexpr std::string_view ANSI_COLOR_RED     = "\x1b[31m";
constexpr std::string_view ANSI_COLOR_GREEN   = "\x1b[32m";
constexpr std::string_view ANSI_COLOR_YELLOW  = "\x1b[33m";
constexpr std::string_view ANSI_COLOR_BLUE    = "\x1b[34m";
constexpr std::string_view ANSI_COLOR_MAGENTA = "\x1b[35m";
constexpr std::string_view ANSI_COLOR_CYAN    = "\x1b[36m";
constexpr std::string_view ANSI_COLOR_RESET   = "\x1b[0m"; //escape code to reset the color after printing the colored text
//string_view provides a lightweight object that offers read-only access to a string or a part of a string 
inline void printColoredText(std::string text, std::string_view colorCode) {
    std::cout << colorCode << text << ANSI_COLOR_RESET ;
}