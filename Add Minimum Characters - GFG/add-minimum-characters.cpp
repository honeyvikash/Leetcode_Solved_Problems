//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string s){    
        int n= s.size();
        int ans=0;
        int start=0,e=n-1;
        while(start<e)
        {
            if(s[start]==s[e])
            {
                start++;
                e--;
            }
            else
            {
                ans++;
                start=0;
                e=n-ans-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends