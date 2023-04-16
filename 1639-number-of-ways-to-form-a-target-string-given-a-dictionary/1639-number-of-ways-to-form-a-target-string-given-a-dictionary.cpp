class Solution {
public:
    int mod = 1e9+7;
    int dp[1001][1001];
    int solve(int idx,vector<vector<int>>& fre,string& tar,int ptr)
    {
        if(ptr>=tar.size())
        return 1;
        if(idx>=fre.size())
        return 0;
        if(dp[idx][ptr]!=-1)
        return dp[idx][ptr];
        int take = 0,notTake = 0;
        long long cnt = fre[idx][tar[ptr]-97];
        if(cnt>0)
        {
            take =((cnt%mod)*(solve(idx+1,fre,tar,ptr+1)%mod)%mod);
        }
        notTake = solve(idx+1,fre,tar,ptr);
        return dp[idx][ptr] = (take+notTake)%mod;
    }
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].size();
        vector<vector<int>> fre(m,vector<int>(26,0));
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                fre[j][words[i][j]-97]++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,fre,target,0);
    }
};