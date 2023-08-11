class Solution {
public:
    
    

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

};


Create a code that will determine whether a string can be a palindrome or not. cpp java not std in function

#include <iostream>
#include <unordered_map>
using namespace std;

bool canBePalindrome(string str) {
    unordered_map<char, int> charCount;

    for (char c : str) {
        if (c != ' ') {  // Ignore spaces
            charCount[c]++;
        }
    }

    int oddCount = 0;
    for (auto it : charCount) {
        if (it.second % 2 != 0) {
            oddCount++;
        }
    }

    return oddCount <= 1;
}
/*In this code, charCount is a hash map that maps characters to their counts. When we use a range-based for loop with auto it :
charCount, the variable it takes on the values of each key-value pair in the hash map.

For each iteration of the loop:

it.first represents the key (character in this case).
it.second represents the value (count of that character).
The loop iterates through each character in the charCount hash map and checks if its count is odd. If the count is odd, it increments the oddCount variable.

So, when I used the term auto it, I was referring to the iterator variable that represents each key-value pair in the charCount hash map during the
loop iteration.*/

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (canBePalindrome(input)) {
        cout << "The string can be rearranged into a palindrome." << endl;
    } else {
        cout << "The string cannot be rearranged into a palindrome." << endl;
    }

    return 0;
}



