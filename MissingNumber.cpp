#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2; // Sum of numbers from 0 to n using the formula n * (n + 1) / 2
    int actualSum = 0;

    for (int num : nums) {
        actualSum += num;
    }

    return expectedSum - actualSum;
}

int main() {
    vector<int> nums = {3, 0, 1};  // Example input
    int missing = missingNumber(nums);
    cout << "Missing number: " << missing << endl;
    return 0;
}
