class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& nums) {
        unordered_map<int,int> mpr,mpc;
        for(auto &a:nums)
            mpr[a[0]]++,
            mpc[a[1]]++;
        int orr = 0 , oc = 0 ;
        for(auto &[a,b]:mpr)
            if(b&1) orr++;
        
        for(auto&[a,b]:mpc)
            if(b&1) oc++;
            
        return orr*(n-oc) + oc*(m-orr);
    }
};