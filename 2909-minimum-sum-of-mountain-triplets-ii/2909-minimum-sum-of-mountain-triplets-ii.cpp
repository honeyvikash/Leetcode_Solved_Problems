class Solution {
public:
    #define ll long long
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>v1 = nums;
        vector<int>v2 = nums;
        for(int i = 1; i<n; i++) 
        {
            v1[i] = min(v1[i-1], nums[i]);
        }
        for (int i = n-2; i>=0; i--) 
        {
            v2[i] = min(v2[i+1], nums[i]);
        }
        
        int ans = INT_MAX;
        bool check = false;
        
        for (int i = 0; i<n-1; i++) 
        {
            if (nums[i]>v1[i] && nums[i]>v2[i])
            {
                ans = min(ans, (nums[i]+v1[i]+v2[i]));
                check = true;
            }
        }
        
        if(check)
        {
            return ans;
        }
        
        return -1;
    }
};