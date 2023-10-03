#pragma once

#include "dir.h"


class Navigation {
public:
    Navigation() = default;
    Navigation (Directory *dir);

    const Directory* getPtrFolder() const;
    //const Directory* findDirectory(const std::string to_find) const;
private:
    Directory *ptr_on_folder_{nullptr};
};

