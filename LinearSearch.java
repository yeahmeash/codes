 comparison between the iterative and recursive versions of a linear search in Java.

Iterative Linear Search

public class LinearSearch {
    public static int linearSearchIterative(int[] arr, int x) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == x) {
                return i; // Return the index where the element is found
            }
        }
        return -1; // Element not found in the array
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 10, 40};
        int x = 10;
        int result = linearSearchIterative(arr, x);
        if (result == -1) {
            System.out.println("Element not present in array");
        } else {
            System.out.println("Element found at index " + result);
        }
    }
}
Recursive Linear Search

public class LinearSearch {
    public static int linearSearchRecursive(int[] arr, int x, int index) {
        if (index >= arr.length) {
            return -1; // Base case: element not found
        }

        if (arr[index] == x) {
            return index; // Element found, return its index
        }

        return linearSearchRecursive(arr, x, index + 1); // Recursive call to check the next element
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 10, 40};
        int x = 10;
        int result = linearSearchRecursive(arr, x, 0);
        if (result == -1) {
            System.out.println("Element not present in array");
        } else {
            System.out.println("Element found at index " + result);
        }
    }
}
