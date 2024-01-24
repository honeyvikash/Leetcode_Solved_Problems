class Solution {
public:
    int maxJump(vector<int>& nums) {
        int n = nums.size(),ans=0;
        if(n==2)
            return nums[1]-nums[0];

        for(int i = 2 ; i < n ; ++i)
            ans = max(nums[i]-nums[i-2],ans);

        return ans;
    }
};