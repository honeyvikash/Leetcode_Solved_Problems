//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        if(C==0 && A==B)return 1;
        if(C==0 && A!=B)return 0;
        int a= floor(((B-A)/(C*1.0)))+1;
        int b= ceil(((B-A)/(C*1.0)))+1;
        if(a>0 && b>0)
        {
          if(a==b)return 1;    
        }
        
         return 0;
         
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends