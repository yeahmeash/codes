#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSymmetricMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Check if the matrix is square
    if (n != matrix[0].size()) {
        return false;
    }

    // Check if the matrix is symmetric
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

string MatrixChallenge(string strArr[], int arrLength) {
    vector<vector<int>> matrix;
    vector<int> row;

    for (int i = 0; i < arrLength; i++) {
        if (strArr[i] == "<>") {
            matrix.push_back(row);
            row.clear();
        } else {
            row.push_back(stoi(strArr[i]));
        }
    }
    
    if (isSymmetricMatrix(matrix)) {
        return "symmetric";
    } else {
        return "not symmetric";
    }
}

int main(void) {
    // Input matrix as a string array
    string A[] = {"5", "0", "<>", "0", "5"};
    int arrLength = sizeof(A) / sizeof(*A);
    
    // Check if the matrix is symmetric and print the result
    cout << MatrixChallenge(A, arrLength) << endl;

    // Input another matrix
    string B[] = {"1", "2", "4", "<>", "2", "1", "1", "<>", "-4", "1", "-1"};
    arrLength = sizeof(B) / sizeof(*B);
    
    // Check if the matrix is symmetric and print the result
    cout << MatrixChallenge(B, arrLength) << endl;
    
    return 0;
}
