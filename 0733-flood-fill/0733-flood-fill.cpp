class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool isValid(int x,int y,int n,int m)
    {
        if(x>=0 && y>=0 && x<n && y<m)
            return true;
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<vector<int>> q;
        q.push({sr,sc});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[sr][sc] = 1;
        while(!q.empty())
        {
            int siz = q.size();
            for(int i=0;i<siz;i++)
            {
                int x = q.front()[0];
                int y = q.front()[1];
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int newx = x+dx[j];
                    int newy = y+dy[j];
                    if(isValid(newx,newy,n,m) && image[newx][newy]==image[x][y] && !vis[newx][newy])
                    {
                        vis[newx][newy] =1;
                        q.push({newx,newy});
                    }
                }
                image[x][y] = color;
            }
        }
        return image;
    }
};