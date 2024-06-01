class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>arr(32,0) ;
        int ans = 0 ;
        
            for(int j=0 ; j<=31 ; j++)
            {
                int mask = 1<<j;
                int cnt = 0 ; 
                for(int i=0 ; i<nums.size() ; i++)
                {
                    if(nums[i] & mask) cnt++;
                }
                
                if(cnt%3==1)
                {
                    ans = ans | mask ;
                }
            }

        return ans ;
         
    }
};