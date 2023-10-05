#include "navigation.h"

#include <iostream>
#include <algorithm>


Navigation::Navigation(Directory *dir) : ptr_on_folder_{dir}{
    std::cout << "I see " << ptr_on_folder_->getName() << std::endl;
}


const Directory* Navigation::getPtrFolder() const {
        return ptr_on_folder_;
    }

const  Directory* Navigation::moveToDir(const Directory* ptr_on_dir) {
    ptr_on_folder_ = ptr_on_dir;
    return getPtrFolder();
 }
