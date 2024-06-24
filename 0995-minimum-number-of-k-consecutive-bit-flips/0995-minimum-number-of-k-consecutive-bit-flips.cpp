class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size(),cnt=0;
        vector<int> da(n+10,0);
        for(int i = 0 ; i < n-k+1 ; ++i)
        {
            if(i!=0)
                da[i]+=da[i-1];

            if(da[i]&1)
            {

                if(nums[i]==1)
                {
                    da[i]++;
                    if(i+k<n)
                        da[i+k]--;
                    cnt++;
                }

            }
            else
            {
                
                if(nums[i]==0)
                {
                    da[i]++;
                    if(i+k<n)
                        da[i+k]--;
                    cnt++;
                }
            }
        }
        

        for(int i = n-k+1 ; i < n ; ++i)
        {
            da[i]+=da[i-1];
            if((da[i]&1)^nums[i] != 1)
                return -1;
        }
        return cnt;
    }
};