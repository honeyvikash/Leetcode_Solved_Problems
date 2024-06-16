class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        
        long long ans = 0;
        map<int,int> mp;
        
        for(auto&a:power)
        {
            mp[a]++;
        }
        
        vector<array<long long , 2>> pv;
        
        for(auto &[a,b]:mp)
        {
            pv.push_back({a,b});
        }
        
        int n = pv.size();
        vector<long long> dp(n,0);
        
        for(int i = 0 ; i < n ; ++i)
        {   
            if(i-1>=0 && pv[i-1][0]<pv[i][0]-2)
                dp[i] = pv[i][0]*pv[i][1] + dp[i-1];
            else if(i-2>=0 && pv[i-2][0]<pv[i][0]-2)
                dp[i] = pv[i][0]*pv[i][1] + dp[i-2];
            else if(i-3>=0)
                dp[i] = pv[i][0]*pv[i][1] + dp[i-3];
            else dp[i] = pv[i][0]*pv[i][1];
            
            ans = max(dp[i],ans);
            if(i!=0)
                dp[i] = max(dp[i],dp[i-1]);
        }
        return ans; 
    }
};