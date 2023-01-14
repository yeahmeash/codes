K’th smallest element in an unsorted array using sorting:
// Java code for Kth smallest element
// in an array
import java.util.Arrays;
import java.util.Collections;

class GFG {
	// Function to return K'th smallest
	// element in a given array
	public static int kthSmallest(Integer[] arr, int K)
	{
		// Sort the given array
		Arrays.sort(arr);

		// Return K'th element in
		// the sorted array
		return arr[K - 1];
	}

	// driver's code
	public static void main(String[] args)
	{
		Integer arr[] = new Integer[] { 12, 3, 5, 7, 19 };
		int K = 2;

		// Function call
		System.out.print("K'th smallest element is "
						+ kthSmallest(arr, K));
	}
}


// Java code to implement the approach with priority queue

import java.util.*;

// Custom comparator class to form the Max heap
class MinHeapComparator implements Comparator<Integer> {

	@Override
	public int compare(Integer number1, Integer number2)
	{
		int value = number1.compareTo(number2);

		// Elements are sorted in reverse order
		if (value > 0) {
			return -1;
		}
		else if (value < 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
}
class GFG {

	// Function to find kth smallest array element
	static int kthSmallest(int[] v, int N, int K)
	{
		// For finding min element we need (Max
		// heap)priority queue
		PriorityQueue<Integer> heap1
			= new PriorityQueue<Integer>(
				new MinHeapComparator());

		for (int i = 0; i < N; ++i) {

			// Insert elements into
			// the priority queue
			heap1.add(v[i]);

			// If current element is less than top, that
			// means there are other k-1 lesser elements are
			// present at bottom
			// thus pop that element and add kth largest
			// element into the heap till curr at last all
			// the greater element than kth element will get
			// pop off and at the top of heap there will be
			// kth smallest element
			if (heap1.size() > K) {
				heap1.remove();
			}
		}

		// Return the top of the heap as kth smallest
		// element
		return heap1.peek();
	}

	// Driver's code
	public static void main(String[] args)
	{
		// Given array
		int[] vec
			= { 10, 5, 4, 3, 48, 15, 6, 2, 33, 53, 10 };

		// Size of array
		int N = vec.length;

		// Given K
		int K = 4;

		// Function Call
		System.out.println("Kth Smallest Element: "
						+ kthSmallest(vec, N, K));
	}
}
