class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans,tmp;
        int n = nums.size();
        for(int i = 0 ; i < n ; ++i)
        {
            if(nums[i]==x)
            {
                tmp.push_back(i);
            }
        }

        for(auto&a:queries)
        {
            if(a>tmp.size())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(tmp[a-1]);
            }
        }
        return ans;
    }
};