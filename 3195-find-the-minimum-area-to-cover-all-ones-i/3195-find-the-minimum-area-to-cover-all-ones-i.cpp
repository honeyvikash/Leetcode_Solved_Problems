class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int mnx=1e9,mny=1e9,mx=0,my=0;
        for(int i = 0 ; i < grid.size() ; ++i)
            for(int j = 0 ; j < grid[0].size() ; ++j)
                if(grid[i][j]==1)
                {
                    mnx = min(i,mnx);
                    mny = min(j,mny);
                    mx  = max(i,mx);
                    my  = max(j,my);
                }
        
        return (mx-mnx+1)*(my-mny+1);
    }
};