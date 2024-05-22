class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0,j = 0;
        long long sum = 0;
        int ans = 1;
        while(j<n)
        {
            sum+=nums[j];
            long long tmp = (long long)nums[j]*(long long)(j-i+1);
            if(tmp-sum<=k)
            ans = max(ans,j-i+1);
            else
            {
                while(tmp-sum>k)
                {
                    sum-=nums[i];
                    i++;
                    tmp = (long long)nums[j]*(long long)(j-i+1);
                }
            }
            j++;
        }
        return ans;
    }
};