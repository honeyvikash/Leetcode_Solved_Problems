class Solution {
public:
    int delr[4]={-1,0,1,0};
    int delc[4]={0,1,0,-1};
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&board)
    {
        vis[r][c]=1;
        int n = board.size(),m=board[0].size();
        for(int k=0;k<4;k++)
        {
            int nr = r + delr[k];
            int nc = c + delc[k];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O')
            {
                dfs(nr,nc,vis,board);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(),m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0]=='O')
            {
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O')
            {
                dfs(i,m-1,vis,board);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && board[0][j]=='O')
            {
                dfs(0,j,vis,board);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O')
            {
                dfs(n-1,j,vis,board);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};