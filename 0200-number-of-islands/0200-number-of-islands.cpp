class Solution {
public:
    
    void bfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>& grid)
    {
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        int n = grid.size(),m = grid[0].size();
        vis[r][c]=1;
        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nr = row+delr[k];
                int nc = col+delc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] 
                   && grid[nr][nc]=='1')
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    bfs(i,j,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};