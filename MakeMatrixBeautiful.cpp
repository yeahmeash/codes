//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int> rowSum(n, 0);
        vector<int> colSum(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rowSum[i] += matrix[i][j];
                colSum[j] += matrix[i][j];
            }
        }

        // Find the maximum target sum (either from rows or columns)
        int targetSum = max(*max_element(rowSum.begin(), rowSum.end()),
                            *max_element(colSum.begin(), colSum.end()));

        // Calculate total operations needed
        int totalOperations = 0;
        for (int i = 0; i < n; i++)
        {
            totalOperations += abs(targetSum - rowSum[i]);
            totalOperations += abs(targetSum - colSum[i]);
        }

        return totalOperations / 2; // Divide by 2 since each operation impacts both row and column
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends


1 2
3 4
Row sums: [3, 7]
Column sums: [4, 6]
Target sum: 7 (max of row sums)
Operations needed for each row:

Row 1: |3 - 7| = 4
Row 2: |7 - 7| = 0
Operations needed for each column:

Column 1: |4 - 7| = 3
Column 2: |6 - 7| = 1
If we sum up all the individual operations calculated:

Total operations = 4 + 0 + 3 + 1 = 8
However, if we look at it closely, each operation affects both a row and a column. For instance, incrementing cell (1, 1) would impact both Row 1 and Column 1. So, we are essentially performing double the number of operations that are necessary.

To avoid counting these operations twice, we divide the totalOperations by 2. In the example above, if we divide 8 by 2, we get the correct answer of 4, which represents the actual number of operations required to make the matrix beautiful.

So, in the code, the line totalOperations / 2 is used to correct for the double-counting of operations and provide the accurate result.
