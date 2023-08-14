//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}


// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
     stack<char> charStack;

    // Push characters onto the stack
    for (int i = 0; i < len; i++) {
        charStack.push(S[i]);
    }

    // Pop characters from the stack to reverse the string
    for (int i = 0; i < len; i++) {
        S[i] = charStack.top();
        charStack.pop();
    }

    return S;
}



chatgpt solution 

#include <iostream>
#include <stack>
using namespace std;

char* reverse(char *S, int len)
{
    stack<char> charStack;

    // Push characters onto the stack
    for (int i = 0; i < len; i++) {
        charStack.push(S[i]);
    }

    // Pop characters from the stack to reverse the string
    for (int i = 0; i < len; i++) {
        S[i] = charStack.top();
        charStack.pop();
    }

    return S;
}

int main() {
    char str[] = "Hello, World!";
    int len = sizeof(str) / sizeof(str[0]) - 1; // Exclude the null terminator

    cout << "Original String: " << str << endl;

    char* reversedStr = reverse(str, len);

    cout << "Reversed String: " << reversedStr << endl;

    return 0;
}
