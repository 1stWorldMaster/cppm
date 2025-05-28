#include <iostream>
#include <fstream>
#include <string>
#include <filesystem> 
#include "init.hpp"

int main(int argc, char* argv[]) {

    // std:: cout<< argc; 

    if (argc > 1) {
        std::string command = argv[1];

        if (command == "init")
            init(".");

        else if (command == "new"){
            if (argc < 3)
                std::cout<< "Requires the folder name"<<std::endl;

            else if (argc == 3)
                init(argv[2]);

            else
                std:: cout<< "Can only intake the one folder name";
        } 


        else if (command == "build") {
            std::cout << "build command is used\n";
        } 
        else {
            std::cout << "Unknown command\n";
        }
    } 
    else {
        std::cout << "No command given\n";
    }

    return 0;
}
