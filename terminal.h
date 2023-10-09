#pragma once
#include "navigation.h"

#include <string>
#include <string_view>


class Terminal{
public:
    Terminal() = delete;
    Terminal(Navigation &nav);
    ~Terminal();

    Navigation *getObj();

     void useLS();
     void useCD();
     void usePWD();
     void useHELP();


    std::string readCommand();

    std::string_view parseCommand(std::string_view query);

private:
    Navigation navigation{nullptr};
};
