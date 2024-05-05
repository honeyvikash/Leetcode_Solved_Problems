class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1 && !visited[i][j])
                    {
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
            }
        }
        int drow[4]={1,0,-1,0};
        int dcol[4]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !visited[nr][nc] && grid[nr][nc]==1)
                {
                    q.push({nr,nc});
                    visited[nr][nc]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && visited[i][j]!=1)
                    ans++;
            }
        }
        return ans;
    }
};