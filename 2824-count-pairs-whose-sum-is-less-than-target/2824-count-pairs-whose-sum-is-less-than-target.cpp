class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,len=nums.size(),j=len-1,ans=0;
        while( i<j )
        {
            if( nums[i]+nums[j] < target )
            {
                ans += j-i;
                i += 1;
            }
            else
                j -= 1;
        }
        return ans;
    }
};