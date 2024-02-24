#include <iostream>
#include <cstdlib>

int main(int argc, char * argv[]) {
    std::string tmp_path = getenv("TMP");
    std::string src_path = argv[1];
    std::string out_path = argv[2];
    std::string command = "powershell -Command \"Expand-Archive -Path '" + src_path + "' -DestinationPath '" + out_path + "'\"";

    system(command.c_str());
}