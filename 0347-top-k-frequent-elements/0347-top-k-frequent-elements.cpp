class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        vector<pair<int,int>>temp_ans;
        unordered_map<int,int>mp;
        for(auto x:v)
        {
            mp[x]++;
        }
        for (auto p : mp)
    {
        // cout << p.first << " " << p.second << endl;
        temp_ans.push_back({p.second,p.first});
    }
        
    sort(temp_ans.begin(), temp_ans.end());
    reverse(temp_ans.begin(), temp_ans.end());
    vector<int>ans;
    for(int i=0;i<k;i++)
    {
        ans.push_back(temp_ans[i].second);
    }
        
        return ans;
        
    }
};