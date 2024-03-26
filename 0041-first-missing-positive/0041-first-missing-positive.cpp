class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size() ;
        for(int i=0 ; i<n ; i++)
        {
            int num = nums[i];
            if(num>=1 && num<=n)
            {
                int ind = num-1 ; 
                if(nums[ind]!=num)
                {
                    swap(nums[ind],nums[i]);
                    i--;
                }
            }
        }

        for(int i=0 ; i<n ; i++)
        {
            if(nums[i]!=i+1) return i+1 ;
        }
        return n+1 ;
    }
};