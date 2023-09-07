#include <iostream>
using namespace std;

// Function to find the maximum A & B value
int findMaxAND(int n, int k) {
    int max_and = 0; // Initialize max_and to 0

    // Iterate through all pairs of integers (A, B) from 1 to n
    for (int A = 1; A <= n; A++) {
        for (int B = A + 1; B <= n; B++) {

            // Calculate the bitwise AND of A and B
            int current_and = A & B;

            // Check if the current_and value is less than K and greater than the current max_and
            if (current_and < k && current_and > max_and) {
                max_and = current_and; // Update max_and with the new maximum
            }
        }
    }

    // Return the maximum A & B value
    return max_and;
}

int main() {
    int t;
    cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        int n, k;
        cin >> n >> k; // Read the values of N and K for the current test case

        // Call the findMaxAND function to get the maximum A & B value
        int result = findMaxAND(n, k);

        // Print the result for the current test case
        cout << result << endl;
    }

    return 0;
}
