#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <sstream>

int main(int argc, char * argv[]) {
    std::filesystem::path projdir = argv[1];
    std::filesystem::path exedir = projdir / "main.exe";
    std::filesystem::path tmpdir = getenv("TMP");
    //std::cout << tmpdir << '\n' << projdir << '\n' << exedir << '\n';
    if (!std::filesystem::exists(exedir)) {
        std::cout << "EXE file doesnt exist.";
        return 1;
    }
    std::stringstream proj_args;
    proj_args << " ";
    for (int i = 2; i < argc; i++) {
        proj_args << argv[i];
        if (i < argc - 1) {
            proj_args << " ";
        }
    }
    std::string proj_command = exedir.string() + proj_args.str();
    //std::cout << "Running your project...\n" << proj_command << '\n';
    system(proj_command.c_str());
    std::cout << "Done!";

    return 0;
}