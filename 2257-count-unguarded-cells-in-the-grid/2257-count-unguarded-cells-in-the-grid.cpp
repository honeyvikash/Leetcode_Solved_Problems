class Solution {
public:
    void markPosition(vector<vector<int>>&matrix,int r,int c,int change_r,int change_c)
    {
        if(r+change_r>=0 && r+change_r<matrix.size() && c+change_c>=0 && c+change_c<matrix[0].size() && matrix[r+change_r][c+change_c]!=0)
        {
            if(matrix[r+change_r][c+change_c]!=1)
            {   matrix[r+change_r][c+change_c]=-1;
                markPosition(matrix,r+change_r,c+change_c,change_r,change_c);
            }
            else
            return;
        }
        else
        return;
    }
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {    
        vector<vector<int>>matrix(n,vector<int>(m,INT_MAX));
        for(int i=0;i<guards.size();i++)
        {
            matrix[guards[i][0]][guards[i][1]]=1;
        }
        for(int i=0;i<walls.size();i++)
        {
            matrix[walls[i][0]][walls[i][1]]=0;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    markPosition(matrix,i,j,1,0);
                    markPosition(matrix,i,j,-1,0);
                    markPosition(matrix,i,j,0,1);
                    markPosition(matrix,i,j,0,-1);
                }
            }
        }

    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==INT_MAX)
            {
                count++;
            }
        }
    }
    return count;
    }
};