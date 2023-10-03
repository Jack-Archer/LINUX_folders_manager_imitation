#include "navigation.h"

#include <iostream>
#include <algorithm>


Navigation::Navigation(Directory *dir) : ptr_on_folder_{dir}{
    std::cout << "I see " << ptr_on_folder_->getName() << std::endl;
}


const Directory* Navigation::getPtrFolder() const {
        return ptr_on_folder_;
    }

/*const Directory* Navigation::findDirectory(const std::string to_find) const {
    std::for_each(this->ptr_on_folder_->getFolders().begin(), this->ptr_on_folder_->getFolders().end(),[this, &to_find](auto D_ptr){
        if(D_ptr->getName() == to_find) {
            std::cout << "yeah" << std::endl;
            return;
        }
    });
   auto it =  std::find(this->ptr_on_folder_->getFolders().begin(), this->ptr_on_folder_->getFolders().end(), [&to_find](auto D_ptr){
        return D_ptr->name_ == to_find;
    });
    if(it != this->ptr_on_folder_->getFolders().end()) {
        return *it;
    } else return nullptr;
    std::cout << "END OF FIND";
}*/
