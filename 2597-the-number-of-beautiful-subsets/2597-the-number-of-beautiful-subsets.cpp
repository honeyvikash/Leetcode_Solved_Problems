class Solution {
public:
    bool check(vector<int>& arr,int k,int x)
    {
        for(int i = 0;i < arr.size();i++)
            if(abs(arr[i] - x) == k)
                return false;
        return true;
    }
    int solve(vector<int>& nums,int k,int i,vector<int>& arr)
    {
        if(i == nums.size())
            return 1;
        int ans = 0;
        if(check(arr,k,nums[i]))
        {
            arr.push_back(nums[i]);
            ans = solve(nums,k,i+1,arr);
            arr.pop_back();
        }
        ans += solve(nums,k,i+1,arr);
        return ans;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> arr;
        return solve(nums,k,0,arr) - 1;
    }
};