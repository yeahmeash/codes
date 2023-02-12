// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

#include <iostream>
using namespace std;

int search(int arr[], int N, int x)
{
	int i;
	for (i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

// Driver's code
int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	int result = search(arr, N, x);
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	return 0;
}


// Java code for linearly searching x in arr[]. If x
// is present then return its location, otherwise
// return -1

class GFG {
	public static int search(int arr[], int x)
	{
		int N = arr.length;
		for (int i = 0; i < N; i++) {
			if (arr[i] == x)
				return i;
		}
		return -1;
	}

	// Driver's code
	public static void main(String args[])
	{
		int arr[] = { 2, 3, 4, 10, 40 };
		int x = 10;

		// Function call
		int result = search(arr, x);
		if (result == -1)
			System.out.print(
				"Element is not present in array");
		else
			System.out.print("Element is present at index "
							+ result);
	}
}
// C++ Recursive Code For Linear Search
#include <iostream>
using namespace std;

int linearsearch(int arr[], int size, int key)
{
	if (size == 0) {
		return -1;
	}
	else if (arr[size - 1] == key) {
		// Return the index of found key.
		return size - 1;
	}
	else {
		int ans = linearsearch(arr, size - 1, key);
		return ans;
	}
}

// Driver's Code
int main()
{
	int arr[5] = {5, 15, 6, 9, 4 };
	int key = 4;

	// Function call
	int ans = linearsearch(arr, 5, key);
	if (ans == -1) {
		cout << "The element " << key << " is not found."
			<< endl;
	}
	else {
		cout << "The element " << key << " is found at "
			<< ans << " index of the given array." << endl;
	}
	return 0;
}


