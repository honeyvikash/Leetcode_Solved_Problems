class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& s) {
        vector<string> ans(s.size());
        vector<int> tm = s;
        sort(tm.rbegin(),tm.rend());
        unordered_map<int,string> mp;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(i==0)
                mp[tm[i]] = "Gold Medal";
            else if(i==1)
                mp[tm[i]] = "Silver Medal";
            else if(i==2)
                mp[tm[i]] = "Bronze Medal";
            else
                mp[tm[i]] = to_string(i+1);
        }
        int j = 0;
        for(auto &a:s)
        {
            ans[j++] = mp[a];
        }
        return ans;
    }
};