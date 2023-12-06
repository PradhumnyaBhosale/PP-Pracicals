#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;
public:
    MyString() : str(nullptr) {}

   
    bool operator==(const MyString& other) const {
        return (strcmp(str, other.str) == 0);
    }

  
    MyString operator+(const MyString& other) const {
        MyString result;
        result.str = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    
    void display() const {
        std::cout << str << std::endl;
    }

    
    void reverse() {
        int len = strlen(str);
        for (int i = 0; i < len / 2; ++i) {
            char temp = str[i];
            str[i] = str[len - i - 1];
            str[len - i - 1] = temp;
        }
    }

    
    bool isPalindrome() const {
        int len = strlen(str);
        for (int i = 0; i < len / 2; ++i) {
            if (str[i] != str[len - i - 1]) {
                return false;
            }
        }
        return true;
    }

    
    int findSubstring(const char* substr) const {
        char* pos = strstr(str, substr);
        if (pos != nullptr) {
            return pos - str;
        }
        return -1;
    }


    friend std::istream& operator>>(std::istream& is, MyString& myStr) {
        char buffer[100];
        is >> buffer;
        myStr.str = new char[strlen(buffer) + 1];
        strcpy(myStr.str, buffer);
        return is;
    }

   
    ~MyString() {
        delete[] str;
    }
};

int main() {
    MyString str1, str2, result;

   
    std::cout << "Enter string 1: ";
    std::cin >> str1;

    std::cout << "Enter string 2: ";
    std::cin >> str2;

  
    if (str1 == str2) {
        std::cout << "Strings are equal." << std::endl;
    } else {
        std::cout << "Strings are not equal." << std::endl;
    }

 
    result = str1 + str2;
    std::cout << "Concatenated string: ";
    result.display();

   
    std::cout << "Reversed string: ";
    result.reverse();
    result.display();

  
    if (result.isPalindrome()) {
        std::cout << "String is a palindrome." << std::endl;
    } else {
        std::cout << "String is not a palindrome." << std::endl;
    }

  
    char substr[50];
    std::cout << "Enter sub-string to find: ";
    std::cin >> substr;
    int pos = result.findSubstring(substr);
    if (pos != -1) {
        std::cout << "Sub-string found at position: " << pos << std::endl;
    } else {
        std::cout << "Sub-string not found." << std::endl;
    }

    return 0;
}
