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

Print all possible permutations of series, both iteratively and Recursively.

    1. Iterative Approach:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

The program enters a do-while loop, where it:

Prints the contents of the nums vector: 1 2 3
Moves to the next permutation using next_permutation(nums.begin(), nums.end()). This will change the nums vector to the next lexicographically greater 
permutation, or it will return false if no further permutation is possible.
This loop continues until all permutations are exhausted.
    All possible permutations (iterative):
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1


void printPermutationsIterative(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    do {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "All possible permutations (iterative):" << endl;
    printPermutationsIterative(nums);

    return 0;
}
recursive solution
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void generatePermutationsRecursive(vector<int>& nums, int start) {
    if (start == nums.size() - 1) {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        swap(nums, start, i);
        generatePermutationsRecursive(nums, start + 1);
        swap(nums, start, i); // Backtrack
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "All possible permutations (recursive):" << endl;
    generatePermutationsRecursive(nums, 0);

    return 0;
}


