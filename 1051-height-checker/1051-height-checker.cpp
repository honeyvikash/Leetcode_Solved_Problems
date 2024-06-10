class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v(heights.begin(),heights.end());
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<heights.size();i++)
        {
            if(v[i]!=heights[i])cnt++;
        }
        return cnt;
    }
};