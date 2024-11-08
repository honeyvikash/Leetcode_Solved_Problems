class Solution {
public:
    int calc(int xr, int bit){
        int k = 0;
        for(int i=bit-1;i>=0;i--){
            bool b = ((1<<i)&xr)>0;
            if(!b) k += (1<<i);

        }
        return k;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int xr = 0;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            xr^=nums[i];
            ans[i] = calc(xr,maximumBit);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};