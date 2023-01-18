class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans=n;
        int i=0,j=0;
        int sum=0;
        int flg=0;
        while(j<n)
        {
            sum+=nums[j];
            if(sum>=target)
            {
                flg=1;
                ans = min(ans,j-i+1);
                while(sum>=target)
                {
                    ans = min(ans,j-i+1);
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
        }
        if(!flg)
        ans=0;
        return ans;
    }
};