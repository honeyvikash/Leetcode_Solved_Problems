class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        for(auto &x:nums)
        {
            if(x==0)return 0;
            if(x<0)ans*=-1;
        }
        return ans;
    }
};