class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end());
        int n = people.size();
        vector<vector<int>> ans(n,{-1});
        for(auto &val : people)
        {
            int need = val[1];
            for(int i=0 ; i<n ; i++)
            {
                if( ans[i][0]==-1 || ans[i][0]==val[0] ) need -= 1;
                if( need==-1 ){
                    ans[i] = val;
                    break;
                }
            }
        }
        return ans;
    }
};