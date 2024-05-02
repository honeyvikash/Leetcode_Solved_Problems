class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> rowCount(rows, 0), colCount(cols, 0);
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                if (grid[i][j] == 1) 
                {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        long long count = 0;
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                if (grid[i][j] == 1) 
                {
                    count += (long long)(rowCount[i] - 1) * (colCount[j] - 1);
                }
            }
        }
        return count;
    }
};