class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> da(n+1,0);
        da[0] = -nums[0] , da[k] = nums[0];
        for(int i = 1 ; i <= n-k ; ++i)
        {
            da[i]+=da[i-1];
            int x = nums[i]+da[i];
            if(x<0)
                return false;
            da[i] += -x;
            da[i+k] += x;
        }
        for(int i = n-k+1 ; i < n ; ++i)
        {
            da[i]+=da[i-1];
            if(nums[i]+da[i]!=0)
                return false;
        }
        return true;
    }
};