class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        long long int sum = 0;
        for(int i=0;i<n;i++)
        {
            dp[i][0] = matrix[i][0];
            sum += dp[i][0];
        }
        for(int i=0;i<m;i++)
        {
            dp[0][i] = matrix[0][i];
            sum += dp[0][i];
        }
        sum -= dp[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j] == 1)
                {
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1; 
                }
                
                sum += dp[i][j];
            }

        }
        return sum;
    }
};