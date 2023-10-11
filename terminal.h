#pragma once
#include "navigation.h"

#include <string>
#include <string_view>

/*enum class Commands {
    LS,
    PWD,
    HELP,
    CD
};*/


class Terminal{
public:
    Terminal() = delete;
    Terminal(Navigation &nav);
    ~Terminal();

    Navigation *getObj();

     void useLS(std::string query);
     void parseLS(std::string_view query);
     void useCD(std::string_view query);
     void parseCD(std::string_view query);
     void usePWD();
     void useHELP();
     void useMKDIR(const std::string new_dir);


    std::string readCommand();

    void  parseCommand(std::string query);

private:
    Navigation navigation{nullptr};
};
