class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i] = pref[i-1]+nums[i];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int sufLen = (n-i-1);
            int prefLen = i;
            int sufSum = pref[n-1]-pref[i];
            int prefSum = (i-1>=0?pref[i-1]:0);
            int sum = ((prefLen*nums[i])-prefSum)+(sufSum-(sufLen*nums[i]));
            ans[i] = sum;
        }
        return ans;
    }
};