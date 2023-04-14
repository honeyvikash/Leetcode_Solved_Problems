class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        string rowStr = s,colStr = s;
        reverse(colStr.begin(),colStr.end());
        vector<vector<int>> dp(len,vector<int>(len,0));
        for(int i=0 ; i<len ; i++){
            for(int j=0 ; j<len ; j++){
                if( colStr[i]==rowStr[j] ){
                    int ans = 0;
                    if( j!=0 )  ans = max(ans,dp[i][j-1]);
                    if( i!=0 )  ans = max(ans,dp[i-1][j]);
                    if( i!=0 && j!=0 )  ans = max(ans,dp[i-1][j-1]+1);
                    else    ans = max(ans,1);
                    dp[i][j] = ans;
                }else{
                    int ans = 0;
                    if( i!=0 )  ans = dp[i-1][j];
                    if( j!=0 )  ans = max(ans,dp[i][j-1]);
                    dp[i][j] = ans;
                }
            }
        }
        // for(auto &val : dp){
        //     for(auto v : val)   cout<<v<<" ";
        //     cout<<"\n";
        // }
        return dp.back().back();
    }
};