class Solution {
public:
    int solve(int val,vector<int>& nums,int p)
    {
        int cnt = 0;
        int n = nums.size();
        int maxi = 0;
        for(int i=1;i<n;)
        {
            if((nums[i]-nums[i-1])<=val)
            {
                cnt++;
                maxi = max(maxi,(nums[i]-nums[i-1]));
                i+=2;
            }
            else
            i++;
        }
        if(cnt>=p)
        return maxi;
        return -1;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l = 0,r = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int val = solve(mid,nums,p);
            if(val!=-1)
            {
                ans = val;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};