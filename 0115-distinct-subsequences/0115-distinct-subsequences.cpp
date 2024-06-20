class Solution {
public:
    int numDistinct(string str, string sub) {
    int n1=str.size(),n2=sub.size();
    vector<vector<double>> dp(n1+1, vector<double>(n2+1,0));

	for(int i=0;i<=n1;i++)
	{
		dp[i][0]=1;
	}
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(str[i-1]==sub[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}

	return dp[n1][n2];
    }
};
