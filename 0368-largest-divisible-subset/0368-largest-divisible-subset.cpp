class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        int maxInd = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
            }
            if(dp[i]>dp[maxInd]) maxInd = i;
        }
        vector<int> ans;
        ans.push_back(nums[maxInd]);
        int k = prev[maxInd];
        while(k!=-1)
        {
            ans.push_back(nums[k]);
            k = prev[k];
        }
        return ans;
    }
};