//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
 stack<int> insertAtBottom(stack<int> St, int X) {
    stack<int> tempStack;
    
    // Pop elements from the original stack and push them onto tempStack
    while (!St.empty()) {
        tempStack.push(St.top());
        St.pop();
    }
    
    // Push the new element onto tempStack
    tempStack.push(X);
    
    // Push elements from tempStack back onto the original stack
    while (!tempStack.empty()) {
        St.push(tempStack.top());
        tempStack.pop();
    }
    
    return St;
}


};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
