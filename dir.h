#pragma once

#include <string>
#include <deque>



class Directory{
    public:
    Directory() = default;
    explicit Directory(const std::string name);

    ~Directory();

    void createDir(const std::string new_dir_name);
    void deleteDir(const std::string dir_to_del);

    const std::string getName() const;
    const void displayFolders() const;
    const int displayFoldCount() const;
    const std::deque<Directory*> getFolders() const;
    const Directory* findDir(const std::string name) const;


    private:
    std::string name_{"root"};
    std::pair<Directory*, std::deque<Directory*>> folders_{nullptr,{}};
    int count_obj_ = 0;
};
