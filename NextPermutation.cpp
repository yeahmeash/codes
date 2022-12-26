#include <bits/stdc++.h>
using namespace std;

// Function to find the next permutation
void nextPermutation(vector<int>& arr)
{
    int n = arr.size(), i, j;

    // Find for the pivot element.
    // A pivot is the first element from
    // end of sequencewhich doesn't follow
    // property of non-increasing suffix
    for (i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            break;
        }
    }

    // Check if pivot is not found
    if (i < 0) {
        reverse(arr.begin(), arr.end());
    }

    // if pivot is found
    else {

        // Find for the successor of pivot in suffix
        for (j = n - 1; j > i; j--) {
            if (arr[j] > arr[i]) {
                break;
            }
        }

        // Swap the pivot and successor
        swap(arr[i], arr[j]);

        // Minimise the suffix part
        reverse(arr.begin() + i + 1, arr.end());
    }
}

// Driver code
int main()
{

    // Given input array
    vector<int> arr = { 1, 2, 3, 6, 5, 4 };

    // Function call
    nextPermutation(arr);

    // Printing the answer
    for (auto i : arr) {
        cout << i << " ";
    }

    return 0;
}
Output
1 2 4 3 5 6 
Time Complexity: O(N), where N is the size of the given array.
Auxiliary Space: O(1)
