#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "template.hpp"
#include "../init.hpp"

// FutureWork: give the function to skip some file or skip all the previous file 

void create_file(const std::string& filepath, const std::string& content) {
    std::ofstream file(filepath);
    if (file.is_open()) {
        file << content;
        file.close();
        std::cout << "Created file: " << filepath << "\n";
    }
    else {
        std::cerr << "Failed to create file: " << filepath << "\n";
    }
}

void init() {
    std::string folders[3] = {"src", "build", "test"};

    for (const auto& folder : folders) {
        if (!std::filesystem::exists(folder)) {
            if (std::filesystem::create_directory(folder))
                std::cout << "Directory '" << folder << "' created.\n";
            else
                std::cerr << "Failed to create directory: " << folder << "\n";
        } 
        else
            std::cout << "Directory '" << folder << "' already exists.\n";

    }


    create_file("CMakeLists.txt", cmake_content);
    create_file("src/main.cpp", main_cpp_content);
    create_file("README.md", readme_content);
    create_file(".gitignore", gitignore_content);
}
