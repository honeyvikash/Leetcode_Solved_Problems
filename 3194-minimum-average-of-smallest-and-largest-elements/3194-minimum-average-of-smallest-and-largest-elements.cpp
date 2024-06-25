class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double ans = 1e9,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() ; ++i)
            ans = min(ans,(nums[i]+nums[n-1-i])/2.0);
        return ans;
    }
};