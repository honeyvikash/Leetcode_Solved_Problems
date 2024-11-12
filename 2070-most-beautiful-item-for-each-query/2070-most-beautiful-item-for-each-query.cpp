class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int>mp;
        for(auto& i : items){
            int price = i[0];
            int beauty = i[1];
            if(mp.find(price) == mp.end()) mp[price] = beauty;
            else mp[price] = max(mp[price], beauty);
        }
        
        int maxBeauty = 0;
        for(auto& [price, beauty] : mp){
            maxBeauty = max(maxBeauty, beauty);
            beauty = maxBeauty;
        }


        vector<int>ans;
        for(auto& q : queries){
            auto it = mp.upper_bound(q);
            if(it != mp.begin()) {
                --it;
                ans.push_back(it->second);
            }
            else ans.push_back(0);
        }
        return ans;
    }
};