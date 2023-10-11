#include <iostream>

#include "dir.h"
#include "navigation.h"
#include "terminal.h"



int main(){

    std::cout << "Let's create your own folders tree !!!" << std::endl;

    Directory root;

   // std::cout << root.getName() << std::endl;


    root.createDir("Home");
    root.createDir("bin");
    root.createDir("docs");

    /*if(root.findDir("Home")) {
        std::cout << "FIND " <<root.findDir("Home")->getName() << std::endl << std::endl;
    } else std::cout << "DIR not find" << std::endl;

    root.displayFolders();
    //std::cout << std::endl << root.displayFoldCount() << std::endl << std::endl;
    root.deleteDir("Home");
     if(root.findDir("Home")) {
        std::cout << "FIND " <<root.findDir("Home")->getName() << std::endl << std::endl;
    } else std::cout << "DIR not find" << std::endl;*/

     root.createDir("System32");
     root.createDir("System64");
     std::cout << std::endl;

    //root.displayFolders();
    //std::cout << std::endl;
    //root.deleteDir("bin");
    //root.displayFolders();


    //root.createDir("Home");
    //root.createDir("bin");

   // root.displayFolders();
    //std::cout << std::endl;

    Navigation in_folder(&root);
    //std::cout << in_folder.getPtrFolder()->getName() << std::endl;
    //std::cout << (in_folder.getPtrFolder()->findDir("Home"))->getName() << std::endl;
    //in_folder.moveToDir(in_folder.getPtrFolder()->findDir("bin"));
    // std::cout << in_folder.getPtrFolder()->getName() << std::endl;


    std::cout << "---START TERMINAL---" << std::endl<< std::endl;
    Terminal terminal(in_folder);

    //terminal.getObj()->getPtrFolder()->displayFolders();
    //std::cout << std::endl;
    //auto nav =  terminal.getObj();
    //auto ptr_dir = terminal.getObj().getPtrFolder()->findDir("System64");

    if(terminal.getObj()->getPtrFolder()->findDir("System64")) {
        terminal.getObj()->moveToDir(terminal.getObj()->getPtrFolder()->findDir("System64"));
       // std::cout<< "Now in DIR  " << terminal.getObj()->getPtrFolder()->getName() <<std::endl;
    }


    terminal.getObj()->getPtrFolder()->createDir("Other");
    //terminal.getObj()->getPtrFolder()->createDir("Other");

    if(terminal.getObj()->getPtrFolder()->findDir("Other")) {
        terminal.getObj()->moveToDir(terminal.getObj()->getPtrFolder()->findDir("Other"));
     }

     terminal.getObj()->getPtrFolder()->createDir("Fuck");
     terminal.getObj()->getPtrFolder()->createDir("The");
     terminal.getObj()->getPtrFolder()->createDir("System");
     //terminal.getObj()->getPtrFolder()->createDir("System");

    std::string user_command{""};
    terminal.useHELP();



   while(user_command != "exit") {
        std::cout << "Jack-Archer$ ";
        user_command.clear();
        user_command = terminal.readCommand();
        terminal.parseCommand(user_command);


        //terminal.useLS();
       // terminal.usePWD();
        //terminal.useHELP();
    }

    std::cout << std::endl << "---END TERMINAL---" << std::endl;

return 0;
}
