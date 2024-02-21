class Solution {
public:
    int maxFrequencyElements(vector<int>& a) {
        unordered_map<int,int> mp;
        int maxi=0;
        for(auto x:a)
        {
            mp[x]++;
            maxi=max(mp[x],maxi);
        }
        int ans=0;
        for(auto x:mp)
        {
             if(x.second==maxi)
                 ans+=maxi;
        }
        return ans;
    }
};