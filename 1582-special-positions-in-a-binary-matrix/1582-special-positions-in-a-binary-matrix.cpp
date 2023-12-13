class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> rsum(n,0);
        vector<int> csum(m,0);
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=0;j<m;j++)
            sum+=mat[i][j];
            rsum[i] = sum;
        }
        for(int j=0;j<m;j++)
        {
            int sum = 0;
            for(int i=0;i<n;i++)
            sum+=mat[i][j];
            csum[j] = sum;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1 && rsum[i]==1 && csum[j]==1)
                ans++;
            }
        }
        return ans;
    }
};