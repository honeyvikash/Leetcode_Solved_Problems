class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
         int n=a.size();
         int m=a[0].size();
         if(n==1) return *min_element(a[0].begin(),a[0].end());
         for(int i=1;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(j==0)
                 {
                     a[i][j]+=min(a[i-1][j],a[i-1][j+1]);
                 }
                 else if(j==m-1)
                 {
                      a[i][j]+=min(a[i-1][j],a[i-1][j-1]);
                 }
                 else
                 {
                      a[i][j]+=min(a[i-1][j],min(a[i-1][j+1],a[i-1][j-1]));
                 }
             }
         }
         return *min_element(a[n-1].begin(),a[n-1].end());
    }
};