class Solution {
public:
    int specialArray(vector<int>& n) {
        map<int,int> mp;
        for(int i = 0 ; i < 1001 ; ++i)
            mp[i] = 0;
        for(auto&a:n)
            mp[a]++;
        
        auto rr = mp.rbegin();
        auto ll = mp.rbegin();
        ll++;
        for(auto it = ll ; it!=mp.rend() ; ++it)
        {
            it->second += rr->second;
            rr++;
        }

        for(auto&[a,b]:mp)
        {
            if(a==b)
                return a;
        }
        return -1;
    }
};