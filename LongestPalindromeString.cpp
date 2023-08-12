//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        
        string ans="";
        int n=S.size();
        
        int maxl=0;
        int l=0;
        int r=0;
        for(int i=0; i<n; i++){
            //if longest substring palindrome is of  odd lemgth
            int left=i;
            int right=i;
            while(left>=0&&right<=(n-1)&&S[left]==S[right]){
                  left--;
                  right++; 
            }
            if(right-left+1>maxl){
                maxl=right-left+1;
                l=left+1;
                r=right-1;
            }
            
            //if longest substring palindrome is of  even lemgth
            left=i;
            right=i+1;
            while(left>=0&&right<=n-1&&S[left]==S[right]){
                left--;
                right++;
            }
            if(right-left+1>2&&right-left+1>maxl){
                maxl=right-left+1;
                l=left+1;
                r=right-1;
            }
        }
        
        for(int i=l; i<=r; i++){
            ans=ans+S[i];
        }
        return ans;
    }


    
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}

// } Driver Code Ends
