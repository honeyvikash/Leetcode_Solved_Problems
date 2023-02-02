class Solution {
public:
    void solve(vector<int> &candidates,int ind,vector<int> &asf,vector< vector<int> >&ans,int target){
        if( target==0 )
        {
            ans.push_back(asf);
            return;
        }
        else if( ind==candidates.size() || 0>target )
        {
            return;
        }
        else
        {
            solve(candidates,ind+1,asf,ans,target);
            while(target>0)
            {
                target -= candidates[ind];
                asf.push_back(candidates[ind]);
                solve(candidates,ind+1,asf,ans,target);
            }

            while( !asf.empty() && asf.back()==candidates[ind] )    asf.pop_back();

        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > ans;
        vector<int> asf;
        solve(candidates,0,asf,ans,target);
        return ans;
    }
};