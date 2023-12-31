class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,vector<int>> m;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            m[s[i]].push_back(i);
        }
        int ans = -1;
        for(auto &i:m)
        {
            int siz = i.second.size();
            int idx1 = i.second[0];
            int idx2 = i.second[siz-1];
            ans = max(ans,idx2-idx1-1);
        }
        return ans;
    }
};