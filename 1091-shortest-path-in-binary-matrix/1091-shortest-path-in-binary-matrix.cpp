class Solution {
public:
    int dx[8] = {-1,0,1,-1,1,-1,0,1};
    int dy[8] = {-1,-1,-1,0,0,1,1,1};
    bool isValid(int x,int y,vector<vector<int>>& grid)
    {
        int n = grid.size();
        if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0)
            return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)
            return -1;
        int n = grid.size();
        int ans = 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = -1;
        while(!q.empty())
        {
            int siz = q.size();
            for(int i=0;i<siz;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                if(x==n-1 && y==n-1)
                    return ans;
                q.pop();
                for(int j=0;j<8;j++)
                {
                    int newX = x+dx[j];
                    int newY = y+dy[j];
                    if(isValid(newX,newY,grid))
                    {
                        grid[newX][newY] = -1;
                        q.push({newX,newY});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};