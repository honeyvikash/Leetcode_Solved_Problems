class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        map<int,vector<int>> m;
        int n = a.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            m[a[i]].push_back(i);
            if(m[a[i]].size()==a[i])
            {
                ans.push_back(m[a[i]]);
                m.erase(a[i]);
            }
        }
        return ans;
    }
};