class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        int x = __lg(n);
        for(int i = 1 ; i <= x; ++i){

            for(int j = 0 ; j < n/(1<<i) ; ++j)
                nums[j] = (j&1?max(nums[j<<1],nums[(j<<1)+1]):min(nums[j<<1],nums[(j<<1)+1]));
        }
        return nums[0];
    }
};