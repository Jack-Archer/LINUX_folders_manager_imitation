#include "navigation.h"

#include <iostream>
#include <algorithm>


Navigation::Navigation(Directory *dir) : ptr_on_folder_{dir}{
    std::cout << "I see " << ptr_on_folder_->getName() << std::endl;
}

Navigation::~Navigation() {
    ptr_on_folder_ = nullptr;
}


Directory* Navigation::getPtrFolder() {
        return ptr_on_folder_;
    }

 void Navigation::moveToDir(Directory* ptr_on_dir) {
    if(ptr_on_dir != nullptr) {
        ptr_on_folder_ = ptr_on_dir;
    } else {
        std::cout << "Directory is not in folder" << std::endl;
    }
 }
