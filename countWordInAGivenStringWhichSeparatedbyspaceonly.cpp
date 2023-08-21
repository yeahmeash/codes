#include <iostream>

int countWords(const char* str) {
    int count = 0;
    bool inWord = false;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (!inWord) {
                count++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    
    return count;
}

int main() {
    const char* input = "This is a sample string";
    int wordCount = countWords(input);
    
    std::cout << "Number of words: " << wordCount << std::endl;
    
    return 0;
}
