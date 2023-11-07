class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> ans;
        set<int> tmp;
        for(auto &i:arr)
        {
            set<int> tmp1;
            tmp1.insert(i);
            for(auto &j:tmp)
            tmp1.insert(j|i);
            tmp = tmp1;
            for(auto &j:tmp)
            ans.insert(j);
        }
        return ans.size();
    }
};