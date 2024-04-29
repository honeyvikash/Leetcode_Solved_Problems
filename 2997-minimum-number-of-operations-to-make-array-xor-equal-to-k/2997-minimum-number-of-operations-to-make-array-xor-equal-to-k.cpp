class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> v(32,0);
        for(auto &a:nums)
        {
            for(int i = 0 ; i < 32 ; ++i)
            {
                if((a>>i)&1)
                    v[i]++;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < 32 ; ++i)
            {
                if((k>>i)&1)
                {
                    if(v[i]%2==0)
                        ans++;
                }
                else
                {
                    if(v[i]%2==1)
                        ans++;
                }
            }
        return ans;
    }
};