#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int newIndex = 0; // Index to place the next non-val element

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) {
            nums[newIndex] = nums[i];
            newIndex++;
        }
    }

    return newIndex;
}

int main() {
    vector<int> nums = {3, 2, 2, 3, 4, 2, 5};  // Example input
    int val = 2; // Value to remove
    int newLength = removeElement(nums, val);

    cout << "New Length: " << newLength << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
