class Solution {
public:
    int findingindex(vector<int>& nums)
    {
        int n=nums.size();
        int s=0,e=n-1;
        if(nums[s]<=nums[e])return 0;
        while(s<=e)
        {
            int m = s + (e - s) / 2;
            int prev = (m - 1 + n) % n;
            int next = (m + 1) % n;
             if (nums[m] <= nums[prev] && nums[m] <= nums[next]) return m;
            else if (nums[m] <= nums[e])
                e = m - 1;
            else if (nums[m] >= nums[s])
                s = m + 1;
        }
        return 0;
    }

    int search(vector<int>& nums, int t) {
       int i = findingindex(nums);
        int s1=0,e1=i-1;
        int s2=i,e2=nums.size()-1;
        int ans1,ans2;
        while(s1<=e1)
        {
            int m=s1+(e1-s1)/2;
            if(nums[m]==t)return m;
            else if(nums[m]<t)
            {
                s1=m+1;
            }
            else e1=m-1;
        }
        while(s2<=e2)
        {
            int m=s2+(e2-s2)/2;
            if(nums[m]==t)return m;
            else if(nums[m]<t)
            {
                s2=m+1;
            }
            else e2=m-1;
        }
        return -1;
    }
};