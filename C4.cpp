#include <iostream>
using namespace std;

void showAddress(const char* str) {
    cout << "Address of each character in the string:" << endl;
    for (int i = 0; str[i] != '\0'; i++) {
        cout << "Character: " << str[i] << ", Address: " << (void*)&str[i] << endl;
    }
}

void concatenateStrings(char* str1, const char* str2) {
    int len1 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }

    int len2 = 0;
    while (str2[len2] != '\0') {
        str1[len1 + len2] = str2[len2];
        len2++;
    }
    str1[len1 + len2] = '\0';
}

int compareStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

int stringLength(const char* str) {
    const char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

void toUpperCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

void reverseString(char* str) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void insertString(char* str1, const char* str2, int pos) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);

    for (int i = len1; i >= pos; i--) {
        str1[i + len2] = str1[i];
    }

    for (int i = 0; i < len2; i++) {
        str1[pos + i] = str2[i];
    }
}

int main() {
    char str1[100], str2[100];
    int choice, pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Show address of each character in string\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of the string\n";
        cout << "5. Convert all lowercase characters to uppercase\n";
        cout << "6. Reverse the string\n";
        cout << "7. Insert a string in another string at a specified position\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string: ";
                cin >> str1;
                showAddress(str1);
                break;

            case 2:
                cout << "Enter first string: ";
                cin >> str1;
                cout << "Enter second string: ";
                cin >> str2;
                concatenateStrings(str1, str2);
                cout << "Concatenated string: " << str1 << endl;
                break;

            case 3:
                cout << "Enter first string: ";
                cin >> str1;
                cout << "Enter second string: ";
                cin >> str2;
                if (compareStrings(str1, str2) == 0) {
                    cout << "Strings are equal.\n";
                } else {
                    cout << "Strings are not equal.\n";
                }
                break;

            case 4:
                cout << "Enter a string: ";
                cin >> str1;
                cout << "Length of the string: " << stringLength(str1) << endl;
                break;

            case 5:
                cout << "Enter a string: ";
                cin >> str1;
                toUpperCase(str1);
                cout << "Uppercase string: " << str1 << endl;
                break;

            case 6:
                cout << "Enter a string: ";
                cin >> str1;
                reverseString(str1);
                cout << "Reversed string: " << str1 << endl;
                break;

            case 7:
                cout << "Enter main string: ";
                cin >> str1;
                cout << "Enter string to insert: ";
                cin >> str2;
                cout << "Enter position to insert: ";
                cin >> pos;
                insertString(str1, str2, pos);
                cout << "Modified string: " << str1 << endl;
                break;

            case 8:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}