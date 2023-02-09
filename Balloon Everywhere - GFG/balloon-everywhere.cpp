//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
         return min({count(s.begin(),s.end(),'b'),
        count(s.begin(),s.end(),'a'),
        count(s.begin(),s.end(),'l')/2,
        count(s.begin(),s.end(),'o')/2,
        count(s.begin(),s.end(),'n')});
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends