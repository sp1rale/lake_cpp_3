// lab
#include <iostream>

using namespace std;

int mystrlen(const char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

char* mystrcpy(char* str1, const char* str2) {
    char* originalStr1 = str1;
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';  
    return originalStr1;
}

char* mystrcat(char* str1, const char* str2) {
    char* originalStr1 = str1;
    while (*str1 != '\0') {
        str1++;
    }
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';  
    return originalStr1;
}

char* mystrchr(char* str, char s) {
    while (*str != '\0') {
        if (*str == s) {
            return str;
        }
        str++;
    }
    return nullptr;
}

char* mystrstr(char* str1, char* str2) {
    while (*str1 != '\0') {
        char* currentStr1 = str1;
        char* currentStr2 = str2;

        while (*currentStr2 != '\0' && *currentStr1 == *currentStr2) {
            currentStr1++;
            currentStr2++;
        }

        if (*currentStr2 == '\0') {
            return str1;  
        }

        str1++;
    }

    return nullptr;  
}

int main() {
   
    const char* str1 = "Hello";
    const char* str2 = " World!";

    cout << "mystrlen result: " << mystrlen(str1) << endl;

    char buffer[20];
    mystrcpy(buffer, str1);
    cout << "mystrcpy result: " << buffer << endl;

    char str3[20] = "Hello";
    mystrcat(str3, str2);
    cout << "mystrcat result: " << str3 << endl;

    char str4[] = "Hello, World!";
    char* foundChar = mystrchr(str4, 'W');
    if (foundChar != nullptr) {
        cout << "mystrchr result: " << foundChar << endl;
    }
    else {
        cout << "Character not found." <<endl;
    }

    char str5[] = "World";
    char* foundStr = mystrstr(str4, str5);
    if (foundStr != nullptr) {
        cout << "mystrstr result: " << foundStr << endl;
    }
    else {
        cout << "Substring not found." << endl;
    }

    return 0;
}