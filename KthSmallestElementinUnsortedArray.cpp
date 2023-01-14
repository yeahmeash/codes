Given an array and a number K where K is smaller than the size of the array.
Find the K’th smallest element in the given array. Given that all array elements are distinct.

  
  K’th smallest element in an unsorted array using Priority Queue:
// C++ code to implement the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the kth smallest array element
int kthSmallest(int arr[], int N, int K)
{

	// For finding min element we need (Max heap)priority
	// queue
	priority_queue<int> pq;

	for (int i = 0; i < K; i++) {
		// First push first K elements into heap
		pq.push(arr[i]);
	}
	// Now check from k to last element
	for (int i = K; i < N; i++) {

		// If current element is < top that means
		// there are other k-1 lesser elements
		// are present at bottom thus, pop that element
		// and add kth largest element into the heap till
		// curr at last all the greater element than kth
		// element will get pop off and at the top of heap
		// there will be kth smallest element
		if (arr[i] < pq.top()) {
			pq.pop();
			// Push curr element
			pq.push(arr[i]);
		}
	}

	// Return top of element
	return pq.top();
}

// Driver's code:
int main()
{
	int N = 10;
	int arr[N] = { 10, 5, 4, 3, 48, 6, 2, 33, 53, 10 };
	int K = 4;

	// Function call
	cout << "Kth Smallest Element is: "
		<< kthSmallest(arr, N, K);
}
K largest(or smallest) elements in an array using priority queue library:
// C++ code for k largest/ smallest elements in an array
#include <bits/stdc++.h>
using namespace std;

// Function to find k largest array element
void kLargest(vector<int>& v, int N, int K)
{
	// Implementation using
	// a Priority Queue
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < N; ++i) {

		// Insert elements into
		// the priority queue
		pq.push(v[i]);

		// If size of the priority
		// queue exceeds k
		if (pq.size() > K) {
			pq.pop();
		}
	}

	// Print the k largest element
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

// Function to find k smallest array element
void kSmalest(vector<int>& v, int N, int K)
{
	// Implementation using
	// a Priority Queue
	priority_queue<int> pq;

	for (int i = 0; i < N; ++i) {

		// Insert elements into
		// the priority queue
		pq.push(v[i]);

		// If size of the priority
		// queue exceeds k
		if (pq.size() > K) {
			pq.pop();
		}
	}

	// Print the k smallest element
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
}

// driver program
int main()
{
	// Given array
	vector<int> arr
		= { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
	// Size of array
	int n = arr.size();
	int k = 3;
	cout << k << " largest elements are : ";
	kLargest(arr, n, k);
	cout << k << " smallest elements are : ";
	kSmalest(arr, n, k);
}

// This code is contributed by Pushpesh Raj.


K’th smallest element in an unsorted array using sorting:
// C++ program to find K'th smallest element
#include <bits/stdc++.h>
using namespace std;

// Function to return K'th smallest element in a given array
int kthSmallest(int arr[], int N, int K)
{
	// Sort the given array
	sort(arr, arr + N);

	// Return k'th element in the sorted array
	return arr[K - 1];
}

// Driver's code
int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int N = sizeof(arr) / sizeof(arr[0]), K = 2;

	// Function call
	cout << "K'th smallest element is "
		<< kthSmallest(arr, N, K);
	return 0;
}

// This code is contributed by Sania Kumari Gupta
// (kriSania804)


K largest(or smallest) elements in an array using sorting:
// C++ code for K largest elements in an array
#include <bits/stdc++.h>
using namespace std;

void kLargest(int arr[], int n, int k)
{
	// Sort the given array arr in reverse order.
	sort(arr, arr + n, greater<int>());

	// Print the first kth largest elements
	for (int i = 0; i < k; i++)
		cout << arr[i] << " ";
}

// Driver code
int main()
{
	int arr[] = { 1, 23, 12, 9, 30, 2, 50 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	kLargest(arr, n, k);
}

// This code is contributed by Aditya Kumar (adityakumar129)

