class Solution {
public:
    bool check(vector<int>& nums,int mid,int maxOperations)
    {
        int cnt = 0 ;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]<mid) continue ;
            else
            {
                if(nums[i]%mid==0)
                {
                    cnt+=nums[i]/mid-1 ;
                }
                else cnt+= (nums[i]/mid) ;
            }
        }
        
        if(cnt<=maxOperations) return true ;
        return false ;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1 ; 
        int high = INT_MIN ; 
        for(auto it : nums)
        {
            high = max(high,it);
        }

        int ans = -1 ;

        while(low<=high)
        {
            int mid = low + (high-low)/2 ;

            if(check(nums,mid,maxOperations)==true)
            {
                ans = mid ;
                high = mid-1 ;
            }
            else low = mid+1 ;
        }
        return ans ;
    }
};