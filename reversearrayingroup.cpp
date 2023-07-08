#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseInGroups(vector<long long>& arr, int n, int k) {
        for (int i = 0; i < n; i += k) {
            int left = i;
            int right = min(i + k - 1, n - 1);
            
            while (left < right) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};

// Utility function to print the array
void printArray(const vector<long long>& arr) {
    for (long long num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<long long> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = arr.size();
    int k = 3;

    cout << "Original array: ";
    printArray(arr);

    Solution sol;
    sol.reverseInGroups(arr, n, k);

    cout << "Array after reversing in groups: ";
    printArray(arr);

    return 0;
}
