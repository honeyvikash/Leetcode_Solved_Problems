class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
        int i=0,j=0,n=nums.size();
        unordered_map<int,int> m;
        int ans = 0;
        while(j<n)
        {
            m[nums[j]]++;
            if(m.size()>=k)
            {
                ans++;
                ans+=(n-j-1);
                while(m.size()>=k && i<=j)
                {
                    m[nums[i]]--;
                    if(m[nums[i]]==0)
                    m.erase(nums[i]);
                    if(m.size()>=k)
                    {
                        ans++;
                        ans+=(n-j-1);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k+1);
    }
};