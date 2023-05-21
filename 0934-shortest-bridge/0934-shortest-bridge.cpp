class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool isValid(int x,int y,vector<vector<int>>& grid)
    {
        int n = grid.size();
        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1)
        return true;
        return false;
    }
    void bfs(queue<pair<int,int>>& q,vector<vector<int>>& grid,vector<vector<int>>& loc)
    {
        while(!q.empty())
        {
            int siz = q.size();
            for(int k=0;k<siz;k++)
            {
                int x = q.front().first;
                int y = q.front().second;
                loc.push_back({x,y});
                q.pop();
                for(int l=0;l<4;l++)
                {
                    int newX = x+dx[l];
                    int newY = y+dy[l];
                    if(isValid(newX,newY,grid))
                    {
                        grid[newX][newY] = 0;
                        q.push({newX,newY});
                    }
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<int>> loc1,loc2;
        int n = grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            int flg = 0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    grid[i][j] = 0;
                    flg = 1;
                    break;
                }
            }
            if(flg)
            break;
        }
        bfs(q,grid,loc1);
        for(int i=0;i<n;i++)
        {
            int flg = 0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    grid[i][j] = 0;
                    flg = 1;
                    break;
                }
            }
            if(flg)
            break;
        }
        bfs(q,grid,loc2);
        int ans = INT_MAX;
        for(int i=0;i<loc1.size();i++)
        {
            int x1 = loc1[i][0];
            int y1 = loc1[i][1];
            for(int j=0;j<loc2.size();j++)
            {
                int x2 = loc2[j][0];
                int y2 = loc2[j][1];
                ans = min(ans,abs(x1-x2)+abs(y1-y2)-1);
            }
        }
        return ans;
    }
};