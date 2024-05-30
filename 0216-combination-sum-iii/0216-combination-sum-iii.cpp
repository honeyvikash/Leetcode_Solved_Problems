class Solution {
public:
vector<vector<int>>ans;
    void solve(int i, int s,vector<int>&v,int &k)
    {
        if(v.size()==k && s==0)
        {
            ans.push_back(v);
            return;
        }
        
        if(i>9)return;

        v.push_back(i);
        solve(i+1,s-i,v,k);
        v.pop_back();
        solve(i+1,s,v,k);
    }
    vector<vector<int>> combinationSum3(int k, int n){
        
        int x = k*(k+1)/2;
        if(x>n)return ans;
        vector<int>v;
        solve(1,n,v,k);
        return ans;
    }
};