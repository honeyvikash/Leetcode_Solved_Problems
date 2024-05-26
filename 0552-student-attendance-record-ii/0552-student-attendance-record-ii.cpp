class Solution {
public:
    long long int mod = 1e9+7 ;
    int checkRecord(int n) {
        long long dp[100001][2][3] ;

        for(int A=0 ; A<=1 ; A++)
        {
            for(int L=0 ; L<=2 ; L++)
            {
                dp[0][A][L]=1 ;
            }
        }

        for(int i=1; i<=n ; i++)
        {
            for(int A=0 ; A<=1 ; A++)
            {
                for(int L=0 ; L<=2 ; L++)
                {
                    long long result = dp[i-1][A][0] ; //present
                    result+=(L+1<=2 ? dp[i-1][A][L+1] : 0); //Late
                    result+=(A+1<=1 ? dp[i-1][A+1][0] : 0); //Absent

                    dp[i][A][L]=result%mod ;
                }
            }
        }
        return dp[n][0][0];
    }
};