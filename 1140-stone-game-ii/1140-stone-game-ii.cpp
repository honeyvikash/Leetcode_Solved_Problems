class Solution {
public:
    int dp[101][101][2];
    int solve(int idx,vector<int>& piles,int m,int flg)
    {
        if(idx>=piles.size())
        return 0;
        if(dp[idx][m][flg]!=-1)
        return dp[idx][m][flg];
        if(flg)
        {
            int sum = 0,ans = INT_MIN;
            for(int i=idx;i<2*m+idx && i<piles.size();i++)
            {
                sum+=piles[i];
                ans = max(ans,sum+solve(i+1,piles,max(m,i-idx+1),0));
            }
            return dp[idx][m][flg] = ans;
        }
        else
        {
            int sum = 0,ans = INT_MAX;
            for(int i=idx;i<2*m+idx && i<piles.size();i++)
            {
                sum+=piles[i];
                ans = min(ans,solve(i+1,piles,max(m,i-idx+1),1)-sum);
            }
            return dp[idx][m][flg] = ans;
        }
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int sum = 0;
        for(auto &i:piles)
        sum+=i;
        return (sum+solve(0,piles,1,1))/2;
    }
};