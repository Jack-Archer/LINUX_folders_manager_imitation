#include <iostream>

#include "dir.h"
#include "navigation.h"



int main(){

    std::cout << "Let's create your own folders tree !!!" << std::endl;

    Directory root;
    std::cout << root.getName() << std::endl;


    root.createDir("Home");
    root.createDir("bin");
    root.createDir("docs");

    root.displayFolders();
    std::cout << std::endl << root.displayFoldCount() << std::endl << std::endl;
    root.deleteDir("Home");

    root.displayFolders();
    std::cout << std::endl;
    root.deleteDir("bin");
    root.displayFolders();
    std::cout << std::endl;

    root.createDir("Home");
    root.createDir("bin");

    root.displayFolders();
    std::cout << std::endl;

    Navigation in_folder(&root);
    std::cout << in_folder.getPtrFolder()->getName() << std::endl;
    std::cout << (in_folder.getPtrFolder()->findDir("Home"))->getName() << std::endl;
    in_folder.moveToDir(in_folder.getPtrFolder()->findDir("Home"));
    std::cout << in_folder.getPtrFolder()->getName();

return 0;
}
