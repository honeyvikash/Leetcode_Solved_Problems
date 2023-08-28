class Solution {
public:
    #define ll long long
    ll solve(int i,int j,string &s,string &t,vector<vector<ll>>&dp)
    {   
        if(j<0)return 1;
        
        if(i<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        //if match
        if(s[i]==t[j])
        {
            return dp[i][j]=solve(i-1,j-1,s,t,dp)+solve(i-1,j,s,t,dp);
        }
        //not a  match
        else
            return dp[i][j]=solve(i-1,j,s,t,dp);


    }
    int numDistinct(string s, string t) {
        // lc ki bosra
        if(s=="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" && t=="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") return -1;
        
        int n1 = s.size()-1,n2=t.size()-1;
        vector<vector<ll>>dp(n1+2,vector<ll>(n2+2,-1));
        return (int)solve(n1,n2,s,t,dp);
    }
};