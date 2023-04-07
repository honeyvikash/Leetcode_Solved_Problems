class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        unordered_map<int,int>mp;
        int cnt=0;
        for(auto &x:a)mp[x]++;
        if(k==0)
        {
            for(auto &x:mp)
            {
                if(x.second>1)cnt++;
            }
        }
        else
        {
            for(auto &x:mp)
            {
                if(mp.count(x.first-k))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};