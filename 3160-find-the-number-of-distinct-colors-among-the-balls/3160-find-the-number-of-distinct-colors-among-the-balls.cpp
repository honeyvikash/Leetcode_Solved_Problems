class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> mp,cmp;
        vector<int> ans;
        for(auto &a:queries)
        {
            int ball = a[0] , color = a[1];
            if(!cmp.count(ball))
            {
                cmp[ball] = color;
                mp[color]++;
            }
            else
            {
                mp[cmp[ball]]--;
                if(mp[cmp[ball]]==0)
                {
                    mp.erase(cmp[ball]);
                }
                mp[color]++;
                cmp[ball] = color;
            }
            ans.push_back(mp.size());
        }
        return ans;
    }
};