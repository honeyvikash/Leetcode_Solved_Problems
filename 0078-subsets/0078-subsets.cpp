class Solution {
public:
    void solve (vector<int>& a,vector<vector<int>> &vc,vector<int> temp,int index)
    {
        if(index >=a.size())
        {
            vc.push_back(temp);
            return;
        }
        // excluding the values
        solve(a,vc,temp,index+1);
        // including the value
        temp.push_back(a[index]);
        solve(a,vc,temp,index+1);
    }
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>>vc;
        vector<int> temp;
        int index=0;
        solve(a,vc,temp,index);
        return vc;
    }
};