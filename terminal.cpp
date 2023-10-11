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
    return s;
}

void Terminal::parseCommand(std::string query) {
    if(!query.empty()) {
        std::string_view query_to_parse{query};
        auto f_begin = query_to_parse.find_first_not_of(' ');
        auto f_space = query_to_parse.find_first_of(' ');

        if(query_to_parse.substr(f_begin, f_space)  == "ls") {
            if(query_to_parse.substr(f_space + 1, query_to_parse.length()).find_first_of('-') == query_to_parse.npos) {
                useLS("ls");
            } else {
                query_to_parse.remove_prefix(f_space);
                parseLS(query_to_parse);
            }
        }
        if(query_to_parse.substr(f_begin, f_space)  == "pwd") {
            usePWD();
        }

         if(query_to_parse.substr(f_begin, f_space)  == "--help") {
            useHELP();
        }

         if(query_to_parse.substr(f_begin, f_space)  == "mkdir") {
            std::string s{"new_dir"};
            useMKDIR(s);
        }
        if(query_to_parse.substr(f_begin, f_space)  == "cd") {
            useCD();
        }
        //std::cerr << query_to_parse << " - Incorrect command" << std::endl;
    }

}

//----------------------------commands and parse composite commands------------------------------

 void Terminal::useLS(std::string query) {
    if(query == "ls") {
        getObj()->getPtrFolder()->displayFolders(1);
    } else if(query == "ls-l-a" || query == "ls-a-l") {
                getObj()->getPtrFolder()->displayFolders(2);
            } else if(query == "ls-l") {
                getObj()->getPtrFolder()->displayFolders(3);
                } else if(query == "ls-a") {
                    getObj()->getPtrFolder()->displayFolders(4);
                } else {
                    std::cerr << query << " - Incorrect command" << std::endl;
                }
}

void Terminal::parseLS(std::string_view query){
   std::string result = "ls";
   auto f_begin{query.find_first_not_of(' ')};
   if(query[f_begin] != '-' || f_begin == query.npos) {
        std::cerr << "Incorrect  mode for LS < " << query << " >" << std::endl;
   } else {
        query.remove_prefix(f_begin);
        auto end_mod{query.find_first_of(' ')};

        if (query.substr(0, end_mod) == "-l" || query.substr(0, end_mod) == "-a") {
            if(query.substr(0, end_mod) == "-l" ) {
                result += "-l";
            }
            if(query.substr(0, end_mod) == "-a" ) {
                result += "-a";
            }
        }
        query.remove_prefix(end_mod);
        f_begin = query.find_first_not_of(' ');
        end_mod = query.substr(f_begin).find_first_of(' ');
        if(query[f_begin] != '-' || f_begin == query.npos) {
            if(f_begin == query.npos) {
                 useLS(result);
            }
            if(query[f_begin] != '-') {
                std::cerr << query.substr(f_begin, query.length())<< " - Incorrect mod" << std::endl;
            }
        } else if (query.substr(f_begin, end_mod) == "-l" || query.substr(f_begin, end_mod) == "-a") {
            if(query.substr(f_begin, end_mod) == "-l" && result[result.size() -1] == 'a') {
                result += "-l";
            }
            if(query.substr(f_begin, end_mod) == "-a" && result[result.size() -1] == 'l') {
                result += "-a";
            }
            useLS(result);
        }
   }
}

 void Terminal::useCD() {
    std::cout << "The command in progress right now" << std::endl;
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

void Terminal::useMKDIR(const std::string new_dir) {
    getObj()->getPtrFolder()->createDir(new_dir);
    std::cout << "Directory \"" << new_dir << "\" was created" << std::endl;
}

