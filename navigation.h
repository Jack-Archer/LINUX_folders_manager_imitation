#pragma once

#include "dir.h"


class Navigation {
public:
    Navigation() = default;
    Navigation (Directory *dir);

    ~Navigation();

     Directory* getPtrFolder();

     void moveToDir(Directory* ptr_on_dir);



private:
    Directory *ptr_on_folder_{nullptr};
};

