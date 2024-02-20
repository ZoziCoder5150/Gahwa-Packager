#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>

int main(int argc, char * argv[]) {
    std::cout << getenv("TMP");
    return 0;
}