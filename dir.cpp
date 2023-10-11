#include "dir.h"

#include <iostream>
#include <algorithm>


Directory::Directory(const std::string name) : name_(name){}

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
    if(isCorrectName(new_dir_name)) {
        Directory *new_dir_ptr = new Directory(new_dir_name);
        ++count_obj_;
        folders_.second.push_back(std::move(new_dir_ptr));
        new_dir_ptr->folders_.first = this;
    } else {
        std::cerr << "incorrect name of directory, directory <" << new_dir_name << "> is allready created !!!" << std::endl;
    }

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

 Directory* Directory::findDir(const std::string name) {
    auto it = std::find_if(folders_.second.begin(), folders_.second.end(), [this, &name](auto D_ptr){
        return D_ptr->getName() == name;
    });
    std::cout << std::endl;
    if(it != folders_.second.end()) {
        return *it;
    } else {
        return nullptr;
    }
 }

//only if FindDir != nullptr
const std::string Directory::getName() const {
   return name_;
}

const void Directory::displayFolders(int mod) const {
    if(folders_.second.empty()) {
        std::cout << "Directory is empty" << std::endl;
    } else {
        switch(mod) {
            case 1:
                for(const auto folder : folders_.second) {
                    std::cout << folder->name_ << "   ";
                }
                std::cout << std::endl;
                break;
            case 2:
                for(const auto folder : folders_.second) {
                        std::cout << folder->name_ << " - size " << sizeof(folder) << std::endl;
                }
                break;
            case 3:
                for(const auto folder : folders_.second) {
                        std::cout << folder->name_ << std::endl;
                }
                break;
            case 4:
                for(const auto folder : folders_.second) {
                    std::cout << folder->name_ << " - size " << sizeof(folder) << "    ";
                }
                std::cout << std::endl;
                break;
        }

    }
}

const int Directory::displayFoldCount() const {
    return count_obj_;
}

const std::deque<Directory*> Directory::getFolders() const {
    return this->folders_.second;
}

  Directory* Directory::getPrev() {
    if(folders_.first == nullptr) {
        return nullptr;
    }
    return folders_.first;
 }


  bool Directory::isCorrectName(const std::string &new_name) {
   bool  correct_name = true;
    std::for_each(folders_.second.begin(), folders_.second.end(),[this, &new_name, &correct_name](auto D_ptr){
            if(D_ptr->name_ == new_name) {
                correct_name = false;
                return;
            }
    });
    return correct_name;
  }
