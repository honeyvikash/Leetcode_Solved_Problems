class Solution {
public:
     int helper(vector<vector<int>> &grid,int r,int c, vector<vector<int>>&dp){

        int row = grid.size();
        int col = grid[0].size();

        if( -1!=dp[r][c] )    return dp[r][c];
        if( r==row-1 && c==col-1 )  return dp[r][c] = grid[r][c];

        int rightCost = INT_MAX,downCost = INT_MAX;
        if( c+1<col )
            rightCost = helper(grid,r,c+1,dp);
        if( r+1<row )
            downCost = helper(grid,r+1,c,dp);
        return dp[r][c] = min(rightCost,downCost)+grid[r][c];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return helper(grid,0,0,dp);
    }
};