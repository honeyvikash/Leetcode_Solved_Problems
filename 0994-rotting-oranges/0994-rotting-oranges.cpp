class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        // vector<vector<int>>vis(n,vector<int>(m));
        int vis[n][m];
        int cnt1 = 0;
        // {{r,c},t}
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else
                {
                    vis[i][j]=0;
                }
                if(grid[i][j]==1)
                {
                    cnt1++;
                }
            }   
        }
        
        int time = 0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int cnt=0;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(t,time);
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nrow = row+drow[k];
                int ncol = col+dcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 
                   && vis[nrow][ncol]==0)
                {
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=cnt1)return -1;
        return time;
    }
};