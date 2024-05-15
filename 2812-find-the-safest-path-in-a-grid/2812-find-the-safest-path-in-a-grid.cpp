class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    bool isValid(int x,int y,int n)
    {
        if(x>=0 && y>=0 && x<n && y<n) return true;
        return false;
    }
    
    bool solve(vector<vector<int>>& grid,vector<vector<int>>&dist,int dis)
    {
        int n = grid.size();
        if(dist[0][0]<dis) return false;
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty())
        {
            int u = q.front().first;
            int v = q.front().second;
            if(u==n-1 && v==n-1)
            return true;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newx = u+dx[i];
                int newy = v+dy[i];
                if(isValid(newx,newy,n) && !vis[newx][newy] && dist[newx][newy]>=dis)
                {
                    q.push({newx,newy});
                    vis[newx][newy] = 1;
                }

            }
        }
        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;
        
        queue<vector<int>> q;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({0,i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            int x = q.front()[1];
            int y = q.front()[2];
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(isValid(newx,newy,n))
                {
                    if(dist[newx][newy]>dist[x][y]+1)
                    {
                        dist[newx][newy] = dist[x][y]+1;
                        q.push({dist[newx][newy],newx,newy});
                    }
                }
            }
        }
        
        int l = 0,r = n;
        int ans = 0;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(solve(grid,dist,mid))
            {
                ans = mid;
                l = mid+1;
            }
            else
            r = mid-1;
        }
        return ans;
    }
}; 