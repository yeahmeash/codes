Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side.
And the rightmost element is always a leader. For example int the array {16, 19, 4, 3, 8, 3}, leaders are 19, 8 and 3?
  
  #include <iostream>
  using namespace std;
void findLeaders (int arr[],int size){
  for (i=0; i<size; i++)
  {
    int j:
    for(j=i+1;j<size;j++){
      if (arr[i]<arr[j])
        break;
    }
    if (j==size)
      cout<<arr[i]<<"":
  }
}
int main()
{
  int len,i;
  cout<<"enter length of array";
  cin>>len;
  int arr[len];
  cout<<"enter the elements of array";
  for (i-0;i<len;i++){
    cin>>arr[i];
  }
