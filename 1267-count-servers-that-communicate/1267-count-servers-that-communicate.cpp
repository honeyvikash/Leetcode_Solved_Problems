class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    cnt++;
            }
            if(cnt>1)
            {
                ans+=cnt;
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==1)
                        grid[i][j] = -1;
                }
            }
        }
        for(int j=0;j<m;j++)
        {
            int cntN = 0,cnt = 0;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j]==-1)
                    cntN++;
                if(grid[i][j]==1)
                    cnt++;
            }
            if(cntN>0 && cnt)
                ans+=cnt;
            else if(cnt>1)
                ans+=cnt;
        }
        return ans;
    }
};