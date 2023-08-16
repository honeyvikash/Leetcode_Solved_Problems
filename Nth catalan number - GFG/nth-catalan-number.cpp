//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    const int mod = 1e9+7;
    long long solve(int n,vector<long long int> &dp)
    {
        if(n<=0) return 1LL;
        
        if(dp[n]!=-1) return dp[n];
        
        long long int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            ans += solve(i,dp)*solve(n-i-1,dp);
        }
        
        return dp[n]=ans;
    }
    long int solveTab(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] = (dp[i] + (1LL * dp[j] * dp[i - j - 1]) % mod) % mod;
            }
        }
        return dp[n];
    }
    int findCatalan(int n) 
    {
        // vector<long long>dp(n+1,-1);
        // return (int)solve(n,dp);
        return solveTab(n);
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends