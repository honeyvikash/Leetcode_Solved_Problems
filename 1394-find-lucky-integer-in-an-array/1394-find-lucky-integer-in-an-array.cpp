class Solution {
public:
    int findLucky(vector<int>& a) {
        unordered_map<int,int>m;
        for(auto &x:a)m[x]++;
        vector<int>v;
        v.push_back(-1);
        for(auto &x:m)
        {
            if(x.first==x.second)v.push_back( x.first);
        }
        sort(v.begin(),v.end(),greater<int>());
        return *max_element(v.begin(),v.end());
    }
};