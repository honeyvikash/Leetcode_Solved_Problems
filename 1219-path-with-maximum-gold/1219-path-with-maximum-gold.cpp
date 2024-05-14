class Solution {
    int sum = 0;
    int tsum = 0;
public:
    void bk(int a,int b,vector<vector<int>>& grid,int n, int m)//,vector<vector<bool>> &bv)
    {
        if((a+1==n || grid[a+1][b]==0 )  
           && (a-1==-1 || grid[a-1][b]==0) 
           && (b-1==-1 || grid[a][b-1]==0) 
           && (b+1==m || grid[a][b+1]==0))
        {
            tsum = max(sum+grid[a][b],tsum);
            return;
        } 
        for(int i = -1 ; i <= 1 ; ++i)
            for(int j = -1 ; j <= 1 ; ++j)
                if(((i==0 && j!=0)||(j==0 && i!=0)) 
                   && (a+i>=0 && a+i<n) && (b+j>=0 && b+j<m ) 
                   && (grid[a+i][b+j]!=0))
                {
                    int t = grid[a][b];
                    sum+=grid[a][b];
                    grid[a][b]=0;
                    bk(a+i,b+j,grid,n,m);
                    sum-=t;
                    grid[a][b]=t;
                }
        return;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int a = 0 ; a < n ; a++)
            for(int b = 0 ; b < m ; b++)
                if(grid[a][b]!=0 )
                {
                    bk(a,b,grid,n,m);
                }
        
        return tsum;
    }
};