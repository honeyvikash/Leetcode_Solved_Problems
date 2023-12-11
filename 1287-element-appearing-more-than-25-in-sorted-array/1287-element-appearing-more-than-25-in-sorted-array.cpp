class Solution {
public:
    int findSpecialInteger(vector<int>& a) {
        unordered_map<int, int>mp;
        int req = a.size() / 4;
        for (auto &x:a) 
        {
            mp[x]++;
        }
        for (auto &x: mp) 
        {
            if (x.second > req) return x.first;
        }
        return -1;
    }
};