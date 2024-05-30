class Solution {
public:
    void solve(int ind, vector<vector<int>> &ans, vector<int> &temp,vector<int> &a, int target){
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<a.size();i++)
        {
            if(i>ind && a[i-1]==a[i]) continue;
            if(a[i]>target) break;
            temp.push_back(a[i]);
            solve(i+1,ans,temp,a,target-a[i]);
            temp.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,ans,temp,candidates,target);
        return ans;
    }
};