#pragma once
#include "navigation.h"

#include <string>
#include <string_view>


class Terminal{
public:
    Terminal() = delete;
    Terminal(Directory *dir);
    ~Terminal();


    std::string readCommand();

    std::string_view parseCommand(std::string_view query);

private:
    Navigation navigation{nullptr};
};
