class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>prefix_xor(a.size()+1);
        for(int i=1;i<=a.size();i++)
        {
            prefix_xor[i]=prefix_xor[i-1]^a[i-1];
        }
        for(auto &query:queries)
        {
            int l=query[0];
            int r=query[1];
            ans.push_back(prefix_xor[r+1]^prefix_xor[l]);
        }
        return ans;
    }
};