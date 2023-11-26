class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vec(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            int cnt = 0;
            int r = 0;
            while(r<n)
            {
                if(mat[r][j]==1)
                {
                    cnt++;
                    vec[r][j] = cnt;
                }
                else
                {
                    cnt = 0;
                    vec[r][j] = 0;
                }
                r++;
            }
        }
        for(int i=0;i<n;i++)
        {
            sort(vec[i].begin(),vec[i].end());
        }
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ar = vec[i][j]*(m-j);
                maxi = max(maxi,ar);
            }
        }
        return maxi;
    }
};