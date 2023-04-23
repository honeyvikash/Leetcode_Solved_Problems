class Solution {
public:
    int mod=1e9+7;
    int dfs_solve(string& s, int& k,int start,vector<int>&dp){
        if(start>=s.length())return 1;
        if(s[start]=='0')return 0;
        if(dp[start]!=-1)return dp[start];
        long curr_num=0;
        long ans=0;
        for(int end=start;end<s.length();end++){
            curr_num=curr_num*10+s[end]-'0';
            if(curr_num>k)break;
            ans=ans%mod+dfs_solve(s,k,end+1,dp)%mod;
        }
        return dp[start]=ans%mod;
    }
    int numberOfArrays(string s, int k) {
        int n=s.length();
        vector<int>dp(n,-1);
        return dfs_solve(s,k,0,dp);
    }
};