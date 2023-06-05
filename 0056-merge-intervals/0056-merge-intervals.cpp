class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>>ans;
        ans.push_back(in[0]);
        for(int i=1 ; i<in.size() ; i++)
        {
            if( in[i][0]<=ans.back().back() )
                ans.back().back() = max(in[i][1],ans.back().back());
            else ans.push_back(in[i]);
        }
        return ans;
    }
}; 