class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        pq.push({dp[0],0});
        int ans = dp[0];
        for(int i=1;i<n;i++)
        {
            while(!pq.empty() && i-pq.top().second>k)
            {
                pq.pop();
            }

            dp[i] = nums[i]+max(0,pq.top().first);
            pq.push({dp[i],i});
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};