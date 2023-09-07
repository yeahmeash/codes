A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. Longest common subsequence (LCS) of 2 sequences is a subsequence, with maximal length, which is common to both the sequences.

Given two sequence of integers,  and , find any one longest common subsequence.

In case multiple solutions exist, print any of them. It is guaranteed that at least one non-empty common subsequence will exist.

Input Format

First line contains two space separated integers,  and , where  is the size of sequence , while  is size of sequence . In next line there are  space separated integers representing sequence , and in third line there are  space separated integers representing sequence .

n m
A1 A2 … An 
B1 B2 … Bm  
Constraints





Output Format

Print the longest common subsequence and each element should be separated by at least one white-space. In case of multiple answers, print any one of them.

Sample Input

5 6
1 2 3 4 1
3 4 1 2 1 3
Sample Output

1 2 3
Explanation

There is no common subsequence with length larger than 3. And "1 2 3", "1 2 1", "3 4 1" are all correct answers.

  #include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for reverse
using namespace std;

vector<int> findLCS(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int m = B.size();

    // Initialize the LCS matrix
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build the LCS matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS from the matrix
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs.push_back(A[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end()); // Reverse to get the correct order
    return lcs;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    vector<int> lcs = findLCS(A, B);

    for (size_t i = 0; i < lcs.size(); i++) { // Change the loop variable type
        cout << lcs[i] << " ";
    }

    return 0;
}
