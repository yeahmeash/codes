/******************************************************************************
Given an array of size N. The task is to find the maximum and the minimum element of the array using the minimum number of comparisons.

Examples:

Input: arr[] = {3, 5, 4, 1, 9}
Output: Minimum element is: 1
              Maximum element is: 9

Input: arr[] = {22, 14, 8, 17, 35, 3}
Output:  Minimum element is: 3
              Maximum element is: 35
*******************************************************************************/

// C++ program of above implementation
#include <iostream>
using namespace std;

void getMinMax(int arr[], int n, int& minVal, int& maxVal)
{
    int i;
    
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            maxVal = arr[0];
            minVal = arr[1];
        }
        else
        {
            minVal = arr[0];
            maxVal = arr[1];
        }
        
        i = 2;
    }
    else
    {
        minVal = arr[0];
        maxVal = arr[0];
        
        i = 1;
    }
    
    while (i < n - 1)
    {       
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > maxVal)
                maxVal = arr[i];
                
            if (arr[i + 1] < minVal)
                minVal = arr[i + 1];
        }
        else
        {
            if (arr[i + 1] > maxVal)
                maxVal = arr[i + 1];
                
            if (arr[i] < minVal)
                minVal = arr[i];
        }
        
        i += 2;
    }   
}

int main()
{
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int arr_size = 6;
    
    int minVal, maxVal;
    getMinMax(arr, arr_size, minVal, maxVal);
    
    cout << "Minimum element is " << minVal << endl;
    cout << "Maximum element is " << maxVal;
    
    return 0;
}
