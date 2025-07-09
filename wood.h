#pragma once
#include <termcolor/termcolor.hpp> //coloring ui single header library. https://github.com/ikalnytskyi/termcolor
#include <iostream>
#include <cstdarg>
#include <sstream>

template <typename... Args>
void errorLog(const bool& shouldCrash, Args&&... args) {

    std::ostringstream oss;
    (oss << ... << args);

    std::cout << "[" << termcolor::red << "-" << termcolor::reset << "] " << oss.str() << std::endl;
    if (shouldCrash) throw std::runtime_error(oss.str());

}

template <typename... Args>
void warningLog(Args&&... args) {
    std::ostringstream oss;
    (oss << ... << args);
    std::cout << "[" << termcolor::yellow << "?" << termcolor::reset << "] " << oss.str() << std::endl;
}
template <typename... Args>
void successLog(Args&&... args) {
    std::ostringstream oss;
    (oss << ... << args);
    std::cout << "[" << termcolor::green << "+" << termcolor::reset << "] " << oss.str() << std::endl;
}

template <typename... Args>
void infoLog(Args&&... args) {
    std::ostringstream oss;
    (oss << ... << args);
    std::cout << "[" << "i" << "] " << oss.str() << std::endl;
}

