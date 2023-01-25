//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // Base Case
        if(s.size()<=3)return s.size();
        int ans=INT_MAX;
        string t="";
        for(int i=0;i<s.size();i++)
        {
            t=t+s[i];
            string su=s.substr(i+1,t.size());
            if(t==su)
            {
                int cnt=su.size()+1+(s.size()-su.size()*2);
                ans=min(ans,cnt);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends