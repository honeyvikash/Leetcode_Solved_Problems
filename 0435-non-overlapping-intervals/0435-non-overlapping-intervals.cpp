class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int ans = 0;
        int n = in.size();
        int st = in[0][0];
        int en = in[0][1];
        
        for(int i=1;i<n;i++)
        {
            int s = in[i][0];
            int e = in[i][1];
            if(s<en)
            {
                ans++;
                st = max(st,s);
                en = min(en,e);
            }
            else
            {
                st = s;
                en = e;
            }
        }
        return ans;
    }
};