class Solution {
public:
    #define ll long long
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll ans = -1e18, cursum = 0;
        unordered_map<int,ll> m;
        m[nums[0]] = 0;
        cursum = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(m.count(nums[i]))
            {
                m[nums[i]] = min(cursum, m[nums[i]]);
            }
            else
            {
                m[nums[i]] = cursum;
            }
            cursum += nums[i];
            if(m.count(nums[i]-k))
            {
                ans = max(cursum-m[nums[i]-k], ans);
            }
            if(m.count(nums[i]+k))
            {
                ans = max(cursum-m[nums[i]+k], ans);
            }
        }
        if(ans == -1e18) ans = 0;
        return ans;
    }
};