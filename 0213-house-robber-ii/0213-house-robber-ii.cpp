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
    
    int rob(vector<int>& a) {
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
        
        vector<int>dp1(n1+1,-1);
        vector<int>dp2(n2+1,-1);
        
        int ans1 = solve(first,n1-1,dp1);
        int ans2 = solve(second,n2-1,dp2);
        return max(ans1,ans2);
    }
};