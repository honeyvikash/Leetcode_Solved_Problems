class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> vt(26,vector<int>(26,INT_MAX));
        for(int i=0;i<26;i++)
        {
            vt[i][i] = 0;
        }
        for(int i=0;i<original.size();i++)
        {
            int r = original[i]-'a';
            int c = changed[i]-'a';
            int z = cost[i];
            vt[r][c] = min(vt[r][c],z);
        }
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    vt[i][j] = min((long)vt[i][j],(long)vt[i][k]+vt[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<source.size();i++)
        {
            int x = source[i]-'a';
            int y = target[i]-'a';
            if(x!=y)
            {
                if(vt[x][y] == INT_MAX) return -1;
                ans += vt[x][y];
            }
        }
        return ans;
    }
};