class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int cnt=0;
        int n=g.size(),m=s.size();
        while(i<n and j<m)
        {
            if(s[j]>=g[i])
            {
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};