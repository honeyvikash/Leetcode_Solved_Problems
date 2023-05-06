class Solution {
    const int MOD = 1e9+7;
public:
    long long power(long long base,long long exp){
        if( 0==exp )    return 1;
        long long temp = power(base,exp/2);
        if( exp&1 ) return ( (temp*temp)%MOD*base%MOD )%MOD;
        else    return (temp*temp)%MOD;
    }
    int numSubseq(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=len-1;
        long long ans = 0;
        while( i<=j ){
            if( nums[i]+nums[j]<=target ){
                ans = ( ans%MOD + (power(2,j-i))%MOD )%MOD;
                i += 1;
            }else
                j -= 1;
        }
        return (int)ans;
    }
};