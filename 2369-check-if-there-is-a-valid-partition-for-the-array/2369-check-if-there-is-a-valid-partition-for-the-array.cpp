class Solution {
public:
    bool canPartition(int i, int n, vector<int>& nums, vector<int>& dp) {
        if (i >= n) return dp[i] = true;
        if (dp[i] != -1) return dp[i];
        
        bool canBePartitioned = false;

        // Case 1: Check for subarray with exactly 2 equal elements
        if (i + 1 < n && nums[i] == nums[i + 1]) {
            canBePartitioned |= canPartition(i + 2, n, nums, dp);
        }

        // Case 2: Check for subarray with exactly 3 equal elements
        if (i + 2 < n && nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
            canBePartitioned |= canPartition(i + 3, n, nums, dp);
        }

        // Case 3: Check for valid 3 consecutive increasing elements
        if (i + 2 < n && nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1) {
            canBePartitioned |= canPartition(i + 3, n, nums, dp);
        }

        return dp[i] = canBePartitioned;
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return canPartition(0, n, nums, dp);
    }
};