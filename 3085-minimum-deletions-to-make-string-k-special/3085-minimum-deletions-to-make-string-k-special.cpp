class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char,int> mp;
        for(auto &a:word)
            mp[a]++;
        
        vector<int> v;
        
        for(auto &[a,b]:mp)
            v.push_back(b);
        
        sort(v.begin(),v.end());
        
        int n = v.size();
        long long sm = 0 , ans = accumulate(v.begin(),v.end(),0LL);
        
        for(int i = 0 ; i < n ; ++i)
        {
            long long tmp = 0;
            for(int j = i ; j < n ; ++j)
            {
                tmp += max(0,v[j]-(v[i]+k));
            }
            ans = min(ans,sm+tmp);
            sm+=v[i];
        }
        return ans;
    }
};