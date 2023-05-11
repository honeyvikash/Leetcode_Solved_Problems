class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1<n2)
        {
            swap(nums1,nums2);
            swap(n1,n2);
        }
        vector<int> dp(n1+1);
        for(int i=0;i<n1;i++)
        {
            int prev = 0;
            for(int j=0;j<n2;j++)
            {
                int cur = dp[j+1];
                if(nums1[i]==nums2[j])
                dp[j+1] = 1+prev;
                else
                dp[j+1] = max(dp[j+1],dp[j]); 
                prev = cur;
            }
        }
       return dp[n2];
    }
};