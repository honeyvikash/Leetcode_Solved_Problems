class Solution {
public:
    bool check(vector<int>& nums, int t,int m)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%m==0) ans+=(nums[i]/m);
            else ans+=(nums[i]/m+1);
        }
        return t>=ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max_int=0,min_int=1e6,ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            max_int=max(nums[i],max_int);
            min_int=min(nums[i],min_int);
        }
        int l=1,r=max_int;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(nums,threshold,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};