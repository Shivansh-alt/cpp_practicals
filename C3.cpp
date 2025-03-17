#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    int count[26] = {0};
    std::string text;

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            text += argv[i];
        }
    } else {
        std::cout << "Enter the text: ";
        std::getline(std::cin, text);
    }

    for (char c : text) {
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            count[c - 'A']++;
        }
    }

    std::cout << "Alphabet\tOccurrences\n";
    for (int i = 0; i < 26; ++i) {
        std::cout << (char)('a' + i) << "\t\t" << count[i] << "\n";
    }

    return 0;
}
