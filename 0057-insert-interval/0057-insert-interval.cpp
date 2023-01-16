class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>all=intervals;
        vector<vector<int>>ans;
        all.push_back(newInterval);
        sort(all.begin(),all.end());
        // Now this ques changes to previous que i.e, merge intervals so
        ans.push_back(all[0]);
        for(int i=1 ; i<all.size() ; i++)
        {
            if( all[i][0]<=ans.back().back() )
                ans.back().back() = max(all[i][1],ans.back().back());
            else ans.push_back(all[i]);
        }
        return ans;
    }
};