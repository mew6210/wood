#include "wood.h"

void errorLog(const std::string& s, bool shouldCrash) {

    std::cout << "[" << termcolor::red << "-" << termcolor::reset << "] " << s << std::endl;
    if (shouldCrash) throw std::runtime_error(s);

}

void warningLog(const std::string& s) {
    std::cout << "[" << termcolor::yellow << "?" << termcolor::reset << "] " << s << std::endl;
}

void successLog(const std::string& s) {
    std::cout << "[" << termcolor::green << "+" << termcolor::reset << "] " << s << std::endl;
}


void infoLog(const std::string& s) {
    std::cout << "[" <<"i"<< "] " << s << std::endl;
}



