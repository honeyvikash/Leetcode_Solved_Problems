class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

        long long sum = 0,ans=0,m=nums.size();
        
        for(int i = 0 ; i < m+1 ;)
        {
            if(i<m && nums[i]-1<=sum)
            {
                sum+=nums[i];
                i++;
            }
            else
            {
                sum+=sum+1;
                ans++;
            }
            
            if(sum>=n)
                break;
        }
        return ans;
    }
};