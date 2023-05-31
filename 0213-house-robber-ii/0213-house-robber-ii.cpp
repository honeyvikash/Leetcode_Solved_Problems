class Solution {
public:
    
    int solve(vector<int>& a,int n,vector<int>& dp)
    {
        if(n<0)return 0;
        
        if(n==0) return a[0];
        
        if(dp[n]!=-1)return dp[n];
        
        int include = solve(a,n-2,dp)+a[n];
        int exclude = solve(a,n-1,dp)+0;
        
        return dp[n]=max(include,exclude);
    }
    
    int solveTab(vector<int>& a)
    {
        int n = a.size();
        vector<int>dp(n+1,0);
        dp[0] = a[0];
        for(int i=1;i<n;i++)
        {
            int in = a[i];
            if(i>1)
            {
                 in = dp[i-2]+a[i];
            }
            
            int ex = dp[i-1]+0;
            dp[i] = max(in,ex);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& a) {
        if(a.empty()) return 0;
        if(a.size() == 1) return a[0];
        
        vector<int>first,second;
        
        for(int i=0;i<a.size();i++)
        {
            if(i==0)
            {
                first.push_back(a[i]);
            }
            else if(i==a.size()-1)
            {
                second.push_back(a[i]);
            }
            else 
            {
                first.push_back(a[i]);
                second.push_back(a[i]);
            }
        }
        
        int n1 = first.size();
        int n2 = second.size();
        
        // vector<int>dp1(n1+1,-1);
        // vector<int>dp2(n2+1,-1);
        
        int ans1 = solveTab(first);
        int ans2 = solveTab(second);
        return max(ans1,ans2);
    }
};