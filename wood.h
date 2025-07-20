#pragma once
#define NOMINMAX
#include <termcolor/termcolor.hpp> //coloring ui single header library. https://github.com/ikalnytskyi/termcolor
#include <iostream>
#include <cstdarg>
#include <sstream>


namespace wood{

    namespace woodInternal{
        void printErrorSignature() {
            std::cout << "[" << termcolor::red << "-" << termcolor::reset << "] ";
        }

        void printWarningSignature(){
            std::cout << "[" << termcolor::yellow << "?" << termcolor::reset << "] ";
        }
        void printSuccessSignature(){
            std::cout << "[" << termcolor::green << "+" << termcolor::reset << "] ";
        }
        void printInfoSignature() {
            std::cout << "[" << "i" << "] ";
        }

        
        template<typename... Args>
        std::string printArgs(Args&&... args) {
            std::ostringstream oss;
            (oss << ... << args);
            std::cout << oss.str();
            return oss.str();
        }
    
    
    }

    template <typename... Args>
    void errorLog(const bool& shouldCrash, Args&&... args) {
        woodInternal::printErrorSignature();
        std::string errorString=woodInternal::printArgs(std::forward<Args>(args)...);
        std::cout << "\n";
        if (shouldCrash) throw std::runtime_error(errorString);
    }




    template <typename... Args>
    void warningLog(Args&&... args) {
        woodInternal::printWarningSignature();
        woodInternal::printArgs(std::forward<Args>(args)...);
        std::cout<<"\n";
    }
    template <typename... Args>
    void successLog(Args&&... args) {
        woodInternal::printSuccessSignature();
        woodInternal::printArgs(std::forward<Args>(args)...);
        std::cout<< "\n";
    }

    template <typename... Args>
    void infoLog(Args&&... args) {
        woodInternal::printInfoSignature();
        woodInternal::printArgs(std::forward<Args>(args)...);
        std::cout << "\n";
    }

}