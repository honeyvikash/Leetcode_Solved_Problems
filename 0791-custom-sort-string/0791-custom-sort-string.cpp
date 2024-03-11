class Solution {
public:
    string customSortString(string o, string s) {
        unordered_map<char, int>mp;
        string ans;
        for(auto i:s) mp[i]++;
        for(auto i:o)
        {
            if(mp.find(i)!=mp.end())
            {
                ans+=string(mp[i], i);
                mp.erase(i);
            }
        }
        for(auto i:mp)
        {
            ans+=string(i.second, i.first);
        }
        return ans;
    }
};