Find the minimum element in a sorted and rotated array using Linear Search:
// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum value
int findMin(int arr[], int n)
{
	int min_ele = arr[0];

	// Traversing over array to
	// find minimum element
	for (int i = 0; i < n; i++) {
		if (arr[i] < min_ele) {
			min_ele = arr[i];
		}
	}

	return min_ele;
}

// Driver code
int main()
{
	int arr[] = { 5, 6, 1, 2, 3, 4 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << findMin(arr, N) << endl;
	return 0;
}

THE EASY WAY USING STL
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int>v{5, 6, 1, 2, 3, 4};
	cout<<"The Minimum Element in the vector is: ";
	cout<<*min_element(v.begin(),v.end())<<endl;
	return 0;
}



Find the minimum element in a sorted and rotated array using Binary Search: 

// C++ program to find minimum
// element in a sorted and rotated array

#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int low, int high)
{
	// This condition is needed to
	// handle the case when array is not
	// rotated at all
	if (high < low)
		return arr[0];

	// If there is only one element left
	if (high == low)
		return arr[low];

	// Find mid
	int mid = low + (high - low) / 2; /*(low + high)/2;*/

	// Check if element (mid+1) is minimum element. Consider
	// the cases like {3, 4, 5, 1, 2}
	if (mid < high && arr[mid + 1] < arr[mid])
		return arr[mid + 1];

	// Check if mid itself is minimum element
	if (mid > low && arr[mid] < arr[mid - 1])
		return arr[mid];

	// Decide whether we need to go to left half or right
	// half
	if (arr[high] > arr[mid])
		return findMin(arr, low, mid - 1);
	return findMin(arr, mid + 1, high);
}

// Driver program to test above functions
int main()
{
	int arr[] = { 5, 6, 1, 2, 3, 4 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "The minimum element is "
		<< findMin(arr, 0, N - 1) << endl;

	return 0;
}

java solution

import java.lang.*;


class Minimum {
    static int solution(int[] a, int low, int high)
    {
        // This condition is needed to handle the case when
        // array is not rotated at all
        if (high < low)
            return a[0];

        // If there is only one element left
        if (high == low)
            return a[low];

        // Find mid
        int mid
                = low + (high - low) / 2; /*(low + high)/2;*/

        // Check if element (mid+1) is minimum element.
        // Consider the cases like {3, 4, 5, 1, 2}
        if (mid < high && a[mid + 1] < a[mid])
            return a[mid + 1];

        // Check if mid itself is minimum element
        if (mid > low && a[mid] < a[mid - 1])
            return a[mid];

        // Decide whether we need to go to left half or
        // right half
        if (a[high] > a[mid])
            return solution(a, low, mid - 1);
        return solution(a, mid + 1, high);
    }

    // Driver Program
    public static void main(String[] args)
    {
        int[] a = { 5, 6, 1, 2, 3, 4 };
        int N = a.length;
        System.out.println("The minimum element is "
                + solution(a, 0, N - 1));
    }
}


