class Solution {
public:
    int solve(vector<int>& nums, int target, int i, map<pair<int, int>, int> &dp) {
        if(i == nums.size()) {
            if(target == 0)
                return 1;
            else
                return 0;
        }
        
        if(dp.find({i, target}) != dp.end()) return dp[{i, target}];

        int left = solve(nums, target - nums[i], i + 1, dp);
        int right = solve(nums, target + nums[i], i + 1, dp);
        return dp[{i, target}] = left + right;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return solve(nums, target, 0, dp);
    }
};