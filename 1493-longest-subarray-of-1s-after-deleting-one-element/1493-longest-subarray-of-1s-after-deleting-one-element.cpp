class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = 0;
        int idx = -1;
        int flg = 0;
        int ans = 0;
        while(j<n)
        {
            if(nums[j]==0)
            {
                if(flg)
                {
                    ans = max(ans,j-i-1);
                    i = idx+1;
                }
                else
                {
                    flg = 1;
                }
                idx = j;
            }
            j++;
        }
        ans = max(ans,j-i-1);
        return ans;
    }
};