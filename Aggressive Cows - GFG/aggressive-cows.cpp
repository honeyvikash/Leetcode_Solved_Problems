//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool can(vector<int>&s,int mid,int k)
    {
        int cntc=1;
        int last = s[0];
        for(int i =1;i<s.size();i++)
        {
            if(s[i]-last>=mid)
            {
                cntc++;
                last=s[i];
                
            }
            if(cntc>=k)return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &s) {
        sort(s.begin(),s.end());
        int l=1,h=s[n-1]-s[0];
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(can(s,mid,k)==true)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
                
            }
        }
        return h;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends