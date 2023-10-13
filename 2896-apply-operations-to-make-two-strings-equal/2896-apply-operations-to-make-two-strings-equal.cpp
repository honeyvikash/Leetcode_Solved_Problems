class Solution {
public:
    int solve(vector<int> &d, int x, int i, int n, vector<vector<int>> &dp)
    {
        if(i==d.size())
        {
            return 0;
        }
        if(dp[i][n]!=-1)
        {
            return dp[i][n];
        }

        int ans=INT_MAX;

        if(i+1<d.size())
        {
            ans= min(ans, d[i+1]-d[i] + solve(d, x, i+2, n, dp));
        }
        ans= min(ans, x+solve(d, x, i+1, n+1, dp));
        if(n>0)
        {
            ans= min(ans, solve(d, x, i+1, n-1, dp));
        }
        return dp[i][n]= ans;
    }
    int minOperations(string s1, string s2, int x) {
        vector<int> a;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
                a.push_back(i);
        }
        if(a.size()%2 != 0)
        {
            return -1;
        }

        int n= s1.length();
        vector<vector<int>> dp(a.size()+1, vector<int> (n, -1));
        return solve(a, x, 0, 0, dp);
    }
};
