class Solution {
public:
    vector<vector<int>> ans;
    void solve(int num,int n,int k,int cnt,vector<int>& ds)
    {
        if(cnt==k)
        {
            ans.push_back(ds);
            return;
        }
        if(num>n)
            return;
        ds.push_back(num);
        solve(num+1,n,k,cnt+1,ds);
        ds.pop_back();
        solve(num+1,n,k,cnt,ds);
    }
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vector<int> ds;
        solve(1,n,k,0,ds);
        return ans;
    }
};