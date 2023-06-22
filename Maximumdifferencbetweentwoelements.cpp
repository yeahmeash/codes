Maximum difference between two elements such that larger element appears after the smaller number
Given an array arr[] of integers, find out the difference between any two elements such that larger element appears after the smaller
number in arr[].

Examples: If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 8 (Diff between 10 and 2). If array is [ 7, 9, 5, 6, 3, 2 ]
  then returned value should be 2 (Diff between 7 and 9)

Time Complexity: O(n^2)
Auxiliary Space: O(1)

Use two loops. In the outer loop, pick elements one by one and in the inner loop calculate the difference of the picked element with every 
other element in the array and compare the difference with the maximum difference calculated so far.
  
  #include <iostream>
  using namespace std;
int maxDiff(int arr[],int arr_size){
  
  int max_diff= arr[l]-arr[0];
  int i, j;
  for(i=0;i<arr_size;i++){
    if(arr[j]-arr[i]>maxDiff){
      maxDiff=arr[j]-arr[i];
    }
    return  maxDiff;
    }
int main()
{
    int len, i;
    cout << "Enter the length of the array\n"; 
    cin>>len;
    int arr[len];
    cout<< "Enter the elements of the array\n";
    for( i=0; i< len; i++) 
    { 
        cin>>arr[i];
    }
    cout<< maxDiff (arr, len);

    return 0;
}
