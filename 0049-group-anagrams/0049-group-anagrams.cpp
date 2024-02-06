class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>m;
        for(auto &x:a)
        {
            string ori=x;
            sort(x.begin(),x.end());
            m[x].push_back(ori);
        }
        for(auto &x:m)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};