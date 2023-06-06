class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int>mina,maxa,ans;
        
        for(int i = 0;i<n;i++)
        {
            int mini= INT_MAX;
            for(int j=0;j<m;j++)
            {
                mini  = min(mini, mat[i][j]);
            }
            mina.push_back(mini);
        }
        
        for(int j=0;j<m;j++)
        {
            int maxi= INT_MIN;
            for(int i = 0;i<n;i++)
            {
                maxi  = max(maxi,mat[i][j]);
            }
            maxa.push_back(maxi);
        }
        
        
        
        for(int i =0;i<mina.size();i++)
        {
            for(int j=0;j<maxa.size();j++)
            {
                if(mina[i]==maxa[j])
                {
                    ans.push_back(mina[i]);
                    break;
                }
            }
        }
        
        return ans;
    }
};