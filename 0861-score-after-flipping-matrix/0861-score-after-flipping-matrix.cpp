class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]!=1)
            {
                for(int j=0;j<m;j++)
                grid[i][j] = !grid[i][j];
            }
        }
        for(int i=1;i<m;i++)
        {
            int cnt1 = 0;
            for(int j=0;j<n;j++)
            {
                if(grid[j][i]==1)
                cnt1++;
            }
            if(cnt1<=n/2)
            {
                for(int j=0;j<n;j++)
                grid[j][i] = !grid[j][i];
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j = m-1;j>=0;j--)
            {
                sum+=grid[i][j]*pow(2,(m-1)-j);
            }
            ans+=sum;
        }
        return ans;
    }
};