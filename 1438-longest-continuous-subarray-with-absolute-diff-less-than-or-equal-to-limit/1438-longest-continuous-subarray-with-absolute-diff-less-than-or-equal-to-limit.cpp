class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        map<int,int> mp;

        int i = 0 , j = 0 , n = nums.size() ,mx = 1 ;

        while(j<n)
        {
            mp[nums[j]]++;

            int d = mp.rbegin()->first-mp.begin()->first;
            if(d <= limit)
            {
                mx = max(mx,j-i+1);
            }
            else if(d >limit)
            {
                while(mp.rbegin()->first-mp.begin()->first > limit)
                {
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                        mp.erase(nums[i]);

                    i++;
                }
            }
            j++;
        }
        return mx;

    }
};