class Solution {
    vector<int> dr = {0,0,1,-1};
    vector<int> dc = {1,-1,0,0};
public:
    bool isPos(int r,int c,int row,int col)
    {
        return (r>=0 && c>=0 && r<row && c<col);
    }
    int helper(int r,int c,vector<vector<int>> &grid,vector<vector<bool>> &visited)
    {
        int row = grid.size();
        int col = grid[0].size();
        visited[r][c] = true;
        bool flag = true;
        for(int i=0 ; i<4 ; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            if( false==isPos(nr,nc,row,col) )   flag = false;
            else if( 1==grid[nr][nc] )   continue;
            else if( false==visited[nr][nc] && false==helper(nr,nc,grid,visited) ) flag = false;
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size(),col = grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        int ans = 0 ;
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                if( false==visited[i][j] && 0==grid[i][j] )
                {
                    // cout<<i<<" "<<j<<" ";
                    bool temp = helper(i,j,grid,visited);
                    // cout<<temp<<"\n";
                    ans += temp;
                }
            }
        }
        return ans;
    }
};