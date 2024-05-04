class Solution {
public:
    int delr[4]={-1,0,1,0};
    int delc[4]={0,1,0,-1};
    void dfs(int r,int c,vector<vector<int>>&ans,vector<vector<int>>& image,int newColor,int iniColor)
    {
        int n = ans.size(),m=ans[0].size();
        ans[r][c]=newColor;
        for(int k=0;k<4;k++)
        {
            int nr = r+delr[k];
            int nc = c+delc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==iniColor && ans[nr][nc]!=newColor)
            {
                dfs(nr,nc,ans,image,newColor,iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int iniColor = image[sr][sc];
        dfs(sr,sc,ans,image,color,iniColor);
        return ans;
    }
};