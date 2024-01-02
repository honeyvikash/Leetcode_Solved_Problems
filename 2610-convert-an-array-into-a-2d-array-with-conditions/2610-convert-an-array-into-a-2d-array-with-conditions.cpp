class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& a) {
        unordered_map<int,int>mp;
        for(auto &i:a)
        {
           mp[i]++;
        }
        int n=a.size();
        vector<vector<int>>ans;
        while(n>0)
        {
            vector<int>t;
            for(auto i:mp)
            {
                if(mp[i.first]>0)
                {
                    t.push_back(i.first);
                    mp[i.first]--;
                    n--;
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};