class Solution {
public:
    
    int BottomUp(vector<int>& c, int rs)
    {
        vector<int>dp(rs+1,INT_MAX);
        
        dp[0]=0;
        
        for(int i=1;i<=rs;i++)
        {
            for(int j=0;j<c.size();j++)
            {
                if(i-c[j]>=0 && dp[i-c[j]]!=INT_MAX)
                {
                    dp[i]=min(dp[i],1+dp[i-c[j]]);
                }
            }
        }
        return dp[rs]==INT_MAX?-1:dp[rs];
    }
    
    int coinChange(vector<int>& c, int rs)
    {
        return BottomUp(c,rs);
    }   
};