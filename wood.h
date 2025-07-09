#pragma once
#include <termcolor/termcolor.hpp> //coloring ui single header library. https://github.com/ikalnytskyi/termcolor
#include <iostream>


void errorLog(const std::string& s, bool shouldCrash);
void warningLog(const std::string& s);
void successLog(const std::string& s);