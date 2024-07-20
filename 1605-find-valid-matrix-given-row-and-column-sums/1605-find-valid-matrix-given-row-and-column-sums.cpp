class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        int n = r.size() ;
        int m = c.size() ;
        vector<vector<int>> ans(n,vector<int>(m,0)) ;
        for(int i=n-1 ; i>=0 ; i--)
        {
            for(int j=m-1 ; j>=0 ; j--)
            {
                int mini = min(r[i],c[j]) ;
                ans[i][j]=mini ; 
                r[i]-=mini ;
                c[j]-=mini ;
            }
        }
        return ans ;
    }
};