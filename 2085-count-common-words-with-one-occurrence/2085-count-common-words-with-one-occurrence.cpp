class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,pair<int,int>> m;
        int ans = 0;
        for(auto &i:words1)
        {
            m[i].first++;
            m[i].second = 1;
        }
        
        for(auto &i:words2)
        {
            m[i].first++;
            m[i].second--;
        }
        for(auto &i:m)
        {
            if(i.second.first==2 && i.second.second==0)
                ans++;
        }
        return ans;
        
    }
};