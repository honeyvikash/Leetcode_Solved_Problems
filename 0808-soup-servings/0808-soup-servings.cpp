class Solution {
public:
    vector<vector<double>>dp;
    double soupServings(int n) {
        if(n >= 4000) return 1;
        dp.resize(n+1,vector<double>(n+1,-1));
        return memo(n,n);
    }
    double memo(int i, int j){
        if(i <= 0 && j <= 0) return 0.5;
        if(i <= 0) return 1.0;
        if(j <= 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 0.25*(memo(i-100,j) + memo(i-75,j-25)+memo(i-50,j-50) + memo(i-25,j-75));
    }
};