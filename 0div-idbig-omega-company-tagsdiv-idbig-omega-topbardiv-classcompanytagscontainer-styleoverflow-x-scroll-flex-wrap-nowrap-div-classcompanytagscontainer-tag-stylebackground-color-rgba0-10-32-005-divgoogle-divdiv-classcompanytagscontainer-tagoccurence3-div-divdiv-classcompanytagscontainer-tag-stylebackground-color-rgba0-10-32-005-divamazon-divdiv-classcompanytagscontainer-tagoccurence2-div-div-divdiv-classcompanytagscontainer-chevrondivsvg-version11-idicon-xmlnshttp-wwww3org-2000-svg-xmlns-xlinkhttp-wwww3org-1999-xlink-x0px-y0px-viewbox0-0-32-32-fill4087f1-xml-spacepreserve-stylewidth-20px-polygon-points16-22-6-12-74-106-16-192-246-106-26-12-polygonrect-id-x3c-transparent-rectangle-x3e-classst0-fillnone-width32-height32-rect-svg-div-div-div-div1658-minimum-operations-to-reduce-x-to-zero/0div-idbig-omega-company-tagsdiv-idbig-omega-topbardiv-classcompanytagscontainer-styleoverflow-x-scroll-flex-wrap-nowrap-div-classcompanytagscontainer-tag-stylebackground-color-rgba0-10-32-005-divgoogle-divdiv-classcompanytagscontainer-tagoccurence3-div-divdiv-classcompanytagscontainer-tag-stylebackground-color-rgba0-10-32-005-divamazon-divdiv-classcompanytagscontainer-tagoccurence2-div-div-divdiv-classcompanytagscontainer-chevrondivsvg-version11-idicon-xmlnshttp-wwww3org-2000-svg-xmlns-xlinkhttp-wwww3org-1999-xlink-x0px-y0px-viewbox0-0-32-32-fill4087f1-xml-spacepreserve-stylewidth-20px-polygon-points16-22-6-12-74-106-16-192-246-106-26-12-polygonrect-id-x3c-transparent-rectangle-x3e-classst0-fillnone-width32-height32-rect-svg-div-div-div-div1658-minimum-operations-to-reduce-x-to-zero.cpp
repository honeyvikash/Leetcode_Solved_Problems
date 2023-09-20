class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tsum = 0;
        for(auto &i:nums)
        tsum+=i;
        int sum = 0;
        int i = 0,j = 0;
        int mini = INT_MAX;
        while(j<n)
        {
            sum+=nums[j];
            if(tsum-sum==x)
            {
                mini = min(mini,n-(j-i+1));
            }
            if(tsum-sum<x)
            {
                while(i<=j && tsum-sum<x)
                {
                    sum-=nums[i];
                    i++;
                }
                if(tsum-sum==x)
                mini = min(mini,n-(j-i+1));
            }
            j++;
        }
        if(mini==INT_MAX)
        return -1;
        return mini;
    }
};