class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum1=0,sum2=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(i==j)
                {
                    sum1+=mat[j][j];    
                }
                else if((i+j)==mat.size()-1)
                {
                    sum2+=mat[i][j];
                }
                
            }
        }
        return sum1+sum2;
    }
};