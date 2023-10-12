class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> m;
        for(auto &i:flowers)
        {
            int a = i[0];
            int b = i[1];
            m[a]++;
            m[b+1]--;
        }
        int pref = m.begin()->second;
        auto it = m.begin();
        it++;
        while(it!=m.end())
        {
            it->second+=pref;
            pref = it->second;
            it++;
        }
        vector<int> ans;
        for(auto &i:people)
        {
            auto it = m.upper_bound(i);
            if(it!=m.begin())
            {
                it--;
                ans.push_back(it->second);
            }
            else
            ans.push_back(0);
        }
        return ans;
    }
};