class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0; i< (matrix.size()) ; i++)
        {
            for(int j=i; j< (matrix[i].size()) ; j++)
            {
                if(i!=j)
               { swap(matrix[i][j], matrix[j][i]);}
            }
        }
        int n= matrix.size();
        int c= matrix[0].size();
         for(int i=0; i< (matrix.size()) ; i++)
        {
            for(int j=0; j< c/2 ; j++)
            {
                
                swap(matrix[i][j], matrix[i][c-j-1]);
            }
        }
        
    }
};