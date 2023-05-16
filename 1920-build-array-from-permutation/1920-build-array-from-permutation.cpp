class Solution {
public:
    vector<int> buildArray(vector<int>& a) {
        vector<int>ans;
        for(int i=0;i<a.size();i++)
        {
            ans.push_back(a[a[i]]);
        }
        return ans;
    }
};