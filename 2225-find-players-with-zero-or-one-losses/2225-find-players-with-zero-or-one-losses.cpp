class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int,int> ind;
        for(auto &i:matches)
        {
            ind[i[1]]++;
            if(ind.find(i[0])==ind.end())
            ind[i[0]] = 0;
        }
        vector<vector<int>> ans;
        vector<int> win,los;
        for(auto &i:ind)
        {
            if(i.second==0)
            win.push_back(i.first);
            if(i.second==1)
            los.push_back(i.first);
        }
        sort(win.begin(),win.end());
        sort(los.begin(),los.end());
        ans.push_back(win);
        ans.push_back(los);
        return ans;
    }
};