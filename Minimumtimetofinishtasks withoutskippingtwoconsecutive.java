Minimum time to finish tasks without skipping two consecutive

Given the time taken by n tasks. Find the minimum time needed to finish the tasks such that skipping of tasks is allowed, but can not skip two consecutive tasks.

Examples : 

Input : arr[] = {10, 5, 7, 10}
Output : 12
We can skip first and last task and
finish these task in 12 min.
  
  
  // Java program to find minimum time to
// finish tasks such that no two
// consecutive tasks are skipped.
import java.io.*;

class GFG {

	// arr[] represents time taken by n
	// given tasks
	static int minTime(int arr[], int n)
	{
		// Corner Cases
		if (n <= 0)
			return 0;

		// Initialize value for the case
		// when there is only one task in
		// task list.
		// First task is included
		int incl = arr[0];
		
		// First task is excluded
		int excl = 0;	

		// Process remaining n-1 tasks
		for (int i = 1; i < n; i++)
		{
		// Time taken if current task is
		// included. There are two
		// possibilities
		// (a) Previous task is also included
		// (b) Previous task is not included
		int incl_new = arr[i] + Math.min(excl,
									incl);

		// Time taken when current task is not
		// included. There is only one
		// possibility that previous task is
		// also included.
		int excl_new = incl;

		// Update incl and excl for next
		// iteration
		incl = incl_new;
		excl = excl_new;
		}

		// Return minimum of two values for
		// last task
		return Math.min(incl, excl);
	}

	// Driver code
	public static void main(String[] args)
	{
		int arr1[] = {10, 5, 2, 7, 10};
		int n1 = arr1.length;
		System.out.println(minTime(arr1, n1));

		int arr2[] = {10, 5, 7, 10};
		int n2 = arr2.length;
		System.out.println(minTime(arr2, n2));

		int arr3[] = {10, 5, 2, 4, 8, 6, 7, 10};
		int n3 = arr3.length;
		System.out.println(minTime(arr3, n3));

	}
}
// This code is contributed by Prerna Saini

// C++ program to find minimum time to finish tasks
// such that no two consecutive tasks are skipped.
#include <bits/stdc++.h>
using namespace std;

// arr[] represents time taken by n given tasks
int minTime(int arr[], int n)
{
	// Corner Cases
	if (n <= 0)
		return 0;

	// Initialize value for the case when there
	// is only one task in task list.
	int incl = arr[0]; // First task is included
	int excl = 0;	 // First task is excluded

	// Process remaining n-1 tasks
	for (int i=1; i<n; i++)
	{
	// Time taken if current task is included
	// There are two possibilities
	// (a) Previous task is also included
	// (b) Previous task is not included
	int incl_new = arr[i] + min(excl, incl);

	// Time taken when current task is not
	// included. There is only one possibility
	// that previous task is also included.
	int excl_new = incl;

	// Update incl and excl for next iteration
	incl = incl_new;
	excl = excl_new;
	}

	// Return minimum of two values for last task
	return min(incl, excl);
}

// Driver code
int main()
{
	int arr1[] = {10, 5, 2, 7, 10};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	cout << minTime(arr1, n1) << endl;

	int arr2[] = {10, 5, 7, 10};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	cout << minTime(arr2, n2) << endl;

	int arr3[] = {10, 5, 2, 4, 8, 6, 7, 10};
	int n3 = sizeof(arr3)/sizeof(arr3[0]);
	cout << minTime(arr3, n3) << endl;

	return 0;
}
