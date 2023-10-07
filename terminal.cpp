#include "terminal.h"

#include <iostream>
#include <algorithm>
#include <string>



Terminal::Terminal(Directory *dir) : navigation(dir) {}

Terminal::~Terminal(){}

std::string Terminal::readCommand() {
    std::string s{""};
    std::getline(std::cin, s);
    std::cout << s << "  DONE" << std::endl;
    return s;
}

std::string_view Terminal::parseCommand(std::string_view query) {
    std::cout << query << " - ready to parse" << std::endl;
}


