class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long long>> helper(4,vector<long long>(n, 0));
        long long curMax=0;
        for(int i=0; i<n; ++i)
        {
            helper[0][i] = (long long)a[0]*b[i];
        }
        for(int j=1; j<4; ++j)
        {
            curMax = helper[j-1][j-1];
            for(int i=j; i<n; ++i)
            {
                helper[j][i] = curMax+(long long)b[i]*a[j];
                curMax = max(curMax, helper[j-1][i]);
            }
        }
        long long ans=LLONG_MIN;
        for(int i=3; i<n; ++i)
        {
            ans = max(ans,helper[3][i]);
        }
        return ans;
    }
};