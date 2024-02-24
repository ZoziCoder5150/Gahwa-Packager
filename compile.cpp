#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <sstream>

int main(int argc, char * argv[]) {
    std::filesystem::path file_to_compile = argv[1];
    std::stringstream compile_cmd;
    compile_cmd << R"1234(powershell.exe -NoExit -Command "&{Import-Module """C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\Microsoft.VisualStudio.DevShell.dll"""; Enter-VsDevShell 3ed31a99 -SkipAutomaticLocation -DevCmdArguments """-arch=x64 -host_arch=x64"""; cl /std:c++17 )1234" << file_to_compile <<  "/Fe" << file_to_compile << ".exe /Fo" << file_to_compile << ".obj";


    if (!std::filesystem::exists(file_to_compile)) {
        std::cout << "Bro, that file doesnt exist.\n";
        return 1;
    }

    system(compile_cmd.str().c_str());
    std::cout << "Done!!!!!!!!!!!\n";
    return 0;
}