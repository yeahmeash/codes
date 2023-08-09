//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
   
    int max_prime=-1; // to handle cases where the input number has no prime factors.
    
    while(N%2==0){       //for even prime number 2
        max_prime=2;
        N/=2;
    }
    
    for(int i=3;i<=sqrt(N);i+=2){  // for odd numbers to sqrt  to limit the range of potential prime factors need to be checked
        while(N%i==0)
        max_prime=i;
        N/=i;
        
    }
    
    if(N>2) max_prime=N;
    
    return max_prime;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}

