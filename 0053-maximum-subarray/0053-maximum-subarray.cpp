class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int maxi = INT_MIN;
        int curr_sum=0;
        int n = a.size();
        for(int i = 0; i<n ; i++)
        {
            curr_sum+=a[i];
            if(curr_sum>maxi)
            {
                maxi = max(maxi , curr_sum);
            }
            if(curr_sum<0)
            {
                curr_sum=0;
            }
        }
        return maxi;
    }
};