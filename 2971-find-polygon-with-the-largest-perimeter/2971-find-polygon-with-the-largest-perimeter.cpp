class Solution {
public:
#define ll long long
    long long largestPerimeter(vector<int>& nums) {
        ll ans = 0, prefs = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i >= 2 && prefs > nums[i])
            {
                ans = nums[i] + prefs;
            }
            
            prefs += nums[i];
        }
        
        return (ans == 0 ? -1 : ans);
    }
};