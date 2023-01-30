class Solution {
public:
    vector<int> decode(vector<int>& a, int f) {
        vector<int>ans;
        ans.push_back(f);
        for(auto &x:a)ans.push_back(x^ans.back());
        return ans;
    }
};