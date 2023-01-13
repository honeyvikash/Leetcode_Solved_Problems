class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xoR=0;
        for(auto &x:nums)
        {
            xoR^=x;
        }
        return xoR;
    }
};