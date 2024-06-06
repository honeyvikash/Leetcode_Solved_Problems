class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        
        if(nums.size()%k)
            return false;
        
        unordered_map<int,int> mp;
        for(auto&a:nums)
            mp[a]++;

        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(mp[nums[i]]==0)
                continue;

            for(int j = 0 ; j < k ; j++)
            {
                if(mp[nums[i]+j]==0)
                    return false;

                mp[nums[i]+j]--;
            }
        }
        return true;
    }
};