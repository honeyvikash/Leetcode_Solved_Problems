class Solution {
public:
    int solve(int idx, int diff, vector<int>& a, vector<unordered_map<int,int>>& dp)
    {
        if(idx<0)return 0;
        
        if(dp[idx].count(diff))
        {
            return dp[idx][diff];
        }
        
        int ans = 0;
        for(int j = idx-1;j>=0;j--)
        {
            if(a[idx]-a[j]==diff)
            {
                ans = max(ans,1+solve(j,diff,a,dp));
            }
        }
        return dp[idx][diff] =ans;
    }
    
    int longestArithSeqLength(vector<int>& a) {
        int n = a.size();
        if(n<=2)return n;
        int ans = 0;
        
        unordered_map<int,int>dp[n+1];
        
        for(int i =1;i<n;i++)
        {
            for(int j = 0; j<i;j++)
            {
                int diff = a[i]-a[j] ;
                int cnt = 1;
                
                if(dp[j].count(diff))
                {
                    cnt = dp[j][diff];
                }
                dp[i][diff] = 1 + cnt;
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};