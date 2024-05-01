class Solution {
public:
    int first(vector<int>&a,int n,int x)
    {
        int l=0,h=n-1;
        int ans = -1;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(a[mid]==x)
            {
                ans = mid;
                h = mid-1;
            }
            else if(a[mid]<x)
            {
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
        return ans;
    }
    int last(vector<int>&a,int n,int x)
    {
        int l=0,h=n-1;
        int ans = -1;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(a[mid]==x)
            {
                ans = mid;
                l = mid+1;
            }
            else if(a[mid]<x)
            {
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int f = first(nums,n,target);
        int l = last(nums,n,target);
        return {f,l};
    }
};