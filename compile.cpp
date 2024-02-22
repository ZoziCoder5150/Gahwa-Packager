#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <sstream>

int main(int argc, char * argv[]) {
    std::filesystem::path file_to_compile = argv[1];
    std::string compile_cmd = ".\\compile.bat " + file_to_compile.string();


    if (!std::filesystem::exists(file_to_compile)) {
        std::cout << "Bro, that file doesnt exist.\n";
        return 1;
    }

    system(compile_cmd.c_str());
    std::cout << "Done!!!!!!!!!!!\n";
    return 0;
}