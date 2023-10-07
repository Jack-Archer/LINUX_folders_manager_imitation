#include "dir.h"

#include <iostream>
#include <algorithm>


Directory::Directory(const std::string name) : name_(name){
}

Directory::~Directory(){
   if(folders_.second.empty()) {
        Directory *ptr_to_del{nullptr};
        folders_.first = ptr_to_del;
        delete ptr_to_del;
        return;
    }

    std::for_each(std::begin(folders_.second), std::end(folders_.second),[this] (auto D_ptr){
        Directory *ptr_to_del{D_ptr};
        folders_.second.pop_front();
        delete ptr_to_del;
    });

    if(folders_.first != nullptr) {
        Directory *ptr_to_del{nullptr};
        folders_.first = ptr_to_del;
        delete ptr_to_del;
    }
}


void Directory::createDir(const std::string new_dir_name) {
    Directory *new_dir_ptr = new Directory(new_dir_name);
    ++count_obj_;
    folders_.second.push_back(std::move(new_dir_ptr));
    new_dir_ptr->folders_.first = this;
}

 void Directory::deleteDir(const std::string dir_to_del)  {
    if(folders_.second.empty()) {
        std::cout << "Directory is empty" << std::endl;
        return;
    }

    auto it_to_del{std::begin(folders_.second)};

    std::for_each(std::begin(folders_.second), std::end(folders_.second),[this, &dir_to_del, &it_to_del](auto D_ptr){
       if(D_ptr->name_ == dir_to_del) {
            Directory *ptr_to_del{D_ptr};
            folders_.second.erase(it_to_del);
            delete ptr_to_del;
            return;
       }
       ++it_to_del;
    });
}

 const Directory* Directory::findDir(const std::string name) const {
    auto it = std::find_if(folders_.second.begin(), folders_.second.end(), [this, &name](auto D_ptr){
        return D_ptr->name_ == name;
    });
    if(it != folders_.second.end()) {
        return *it;
    } else {
        return nullptr;
    }
 }

const std::string Directory::getName() const {
   return name_;
}

const void Directory::displayFolders() const {
    if(folders_.second.empty()) {
        std::cout << "Directory is empty" << std::endl;
    } else {
        for(const auto folder : folders_.second) {
            std::cout << folder->name_ << std::endl;
        }
    }

}

const int Directory::displayFoldCount() const {
    return count_obj_;
}

const std::deque<Directory*> Directory::getFolders() const {
    return this->folders_.second;
}

