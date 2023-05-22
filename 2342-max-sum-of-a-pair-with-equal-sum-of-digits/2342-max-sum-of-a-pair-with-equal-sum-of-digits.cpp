class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = 0;
        map<int,multiset<int>> m;
        for(int i=0;i<nums.size();i++)
        {
            int tmp = nums[i];
            int sum = 0;
            while(tmp)
            {
                sum+=tmp%10;
                tmp/=10;
            }
            m[sum].insert(nums[i]);
        }
        for(auto &i:m)
        {
            if(i.second.size()>1)
            {
                auto it = i.second.end();
                it--;
                int sum = *it;
                it--;
                sum+=*it;
                ans = max(ans,sum);
            }
        }
        if(ans==0)return -1;
        return ans;
    }
};