class Solution {
public:
    int solveRec(vector<vector<char>>& mat,int i,int j,int &maxi)
    {
        // Base Case
        if(i>=mat.size() || j>=mat[0].size())
        {
            return 0;
        }
        
        int right=solveRec(mat,i,j+1,maxi);
        int diag=solveRec(mat,i+1,j+1,maxi);
        int down=solveRec(mat,i+1,j,maxi);
        
        if(mat[i][j]=='1')
        {
            int ans=1+min({right,diag,down});
            maxi=max(maxi,ans);
            return ans;
        }
        else
            return 0;
        
    }
    
    int solveMem(vector<vector<char>>& mat,int i,int j,int &maxi, vector<vector<int>>&dp)
    {
        // Base Case
        if(i>=mat.size() || j>=mat[0].size())
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int right=solveMem(mat,i,j+1,maxi,dp);
        int diag=solveMem(mat,i+1,j+1,maxi,dp);
        int down=solveMem(mat,i+1,j,maxi,dp);
        
        if(mat[i][j]=='1')
        {
            dp[i][j] =1+min({right,diag,down});
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else
            return dp[i][j]=0;
        
    }
    
    int maximalSquare(vector<vector<char>>& mat) {
        // int maxi=0;
        // solveRec(mat,0,0,maxi);
        // return maxi*maxi;
        
        int maxi=0;
        int row=mat.size(),col=mat[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col,-1));
        solveMem(mat,0,0,maxi,dp);
        return maxi*maxi;
            
    }
};