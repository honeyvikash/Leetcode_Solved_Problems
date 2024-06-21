class Solution {
public:
    int maxSatisfied(vector<int>& nums, vector<int>& arr, int k) {
        int n = nums.size();
        int i = 0 , j = 0 , sm = 0 , mx = 0;

        for(int i = 0 ; i < n ; ++i)
            sm += nums[i]*(1-arr[i]);

        while(j<n)
        {
            if(arr[j]==1)
                sm+=nums[j];

            if(j-i+1==k)
            {
                mx = max(mx,sm);

                if(arr[i]==1)
                    sm-=nums[i];
                i++;
            }
            j++;
        }
        return mx;
    }
};