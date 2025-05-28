#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

#include "template.hpp"
#include "../init.hpp"

// TODO: Add option to skip specific files or all previously created files

namespace fs = std::filesystem;

void create_file(const fs::path& filepath, const std::string& content) {
    std::ofstream file(filepath);
    if (file) {
        file << content;
        std::cout << "✅ Created file: " << filepath << "\n";
    }
    else
        std::cerr << "❌ Failed to create file: " << filepath << "\n";
}

void create_dir(const fs::path& dir_path) {
    if (!fs::exists(dir_path)) {
        if (fs::create_directories(dir_path))
            std::cout << "📁 Directory created: " << dir_path << "\n";

        else
            std::cerr << "❌ Failed to create directory: " << dir_path << "\n";

    }
    else
        std::cout << "ℹ️ Directory already exists: " << dir_path << "\n";
}

void init(const std::string& base_folder) {

    fs::path base_path(base_folder);

    // if (!fs::exists(base_path))
        create_dir(base_path);

    const std::vector<std::string> subfolders = { "src", "build", "test" };
    for (const auto& sub : subfolders) 
        create_dir(base_path / sub);

    // File creation
    create_file(base_path / "CMakeLists.txt", cmake_content);
    create_file(base_path / "src/main.cpp", main_cpp_content);
    create_file(base_path / "README.md", readme_content);
    create_file(base_path / ".gitignore", gitignore_content);
}
