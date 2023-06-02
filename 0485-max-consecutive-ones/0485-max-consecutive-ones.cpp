class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(),cnt=0,maxi=0;
        int i=0;
        while(i<n)
        {
            if(nums[i]==1)
            {
                cnt++;
                maxi=max(cnt,maxi);
            }
            else
            {
                cnt=0;
            }
            i++;
        }
        return maxi;
    }
};