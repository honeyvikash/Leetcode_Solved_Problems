class Solution {
public:
    map<pair<int,int>,int> dp;
    int solve(int idx,vector<int>& arr1,vector<int>& arr2,int prev)
    {
        if(idx==arr1.size())return 0;
        
        if(dp.find({idx,prev})!=dp.end()) return dp[{idx,prev}];
        
        int id = upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        
        int ans = INT_MAX/2;
        
        if(arr1[idx]>prev)
        {
           ans = solve(idx+1,arr1,arr2,arr1[idx]); 
        }
            
        if(id<arr2.size())
        {
            ans = min(ans,1+solve(idx+1,arr1,arr2,arr2[id]));
        }
        
        return dp[{idx,prev}] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        dp.clear();
        
        sort(arr2.begin(),arr2.end());
        
        int ans = solve(0,arr1,arr2,INT_MIN);
        
        if(ans==INT_MAX/2) return -1;
        
        return ans;
    }
};