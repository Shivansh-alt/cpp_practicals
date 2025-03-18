#include <iostream>
#include <fstream>
#include <string>

void copyFileWithoutSpaces(const std::string& sourceFile, const std::string& targetFile) {
    std::ifstream source(sourceFile);
    std::ofstream target(targetFile);

    if (source.is_open() && target.is_open()) {
        char c;
        while (source.get(c)) {
            if (!std::isspace(c)) {
                target.put(c);
            }
        }

        source.close();
        target.close();
        std::cout << "File copied successfully without whitespaces." << std::endl;
    } else {
        std::cerr << "Unable to open one or both files." << std::endl;
    }
}

int main() {
    const std::string sourceFile = "source.txt";
    const std::string targetFile = "target.txt";

    copyFileWithoutSpaces(sourceFile, targetFile);

    return 0;
}
