#include "terminal.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <list>
#include <fstream>



Terminal::Terminal(Navigation &nav) : navigation(nav) {}

Terminal::~Terminal(){}

Navigation *Terminal::getObj() {
    return &navigation;
}

std::string Terminal::readCommand() {
    std::string s{""};
    std::getline(std::cin, s);
    //std::cout << s << "  DONE" << std::endl;
    return s;
}

std::string_view Terminal::parseCommand(std::string_view query) {
    //std::cout << query << " - ready to parse" << std::endl;
}

//----------------------------commands------------------------------

 void Terminal::useLS() {
   getObj()->getPtrFolder()->displayFolders();
}

 void Terminal::useCD() {
    //realize change directory method
}

 void Terminal::usePWD() {
    std::list<std::string> ss;
    auto ptr{getObj()->getPtrFolder()};
    ss.push_front(getObj()->getPtrFolder()->getName());
    while(ptr->getPrev() != nullptr) {
        ss.push_front((ptr->getPrev()->getName()) + "/");
        ptr = ptr->getPrev();
    }
    for(auto s : ss) {
        std::cout << s;
    }
    ss.clear();
    std::cout << std::endl;
}

void Terminal::useHELP() {
    std::fstream fs;
    std::string s{""};

    fs.open("help.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    if(!fs.is_open()) {
        std::cerr << "Failed to open Help file" << std::endl;
    } else {
        while(!fs.eof()) {
            s.clear();
            std::getline(fs, s);
            std::cout << s << std::endl;
        }
    }

    fs.close();
}

