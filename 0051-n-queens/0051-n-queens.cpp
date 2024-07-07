class Solution {
public:
    void checkQueen(vector<vector<string>> &ans, vector<string> &arr, int row, int n)
	{
		if (row == arr.size())
		{
			ans.push_back(arr);
			return;
		}
		for (int col = 0; col < arr.size(); col++)
		{
			if (isSafe(arr, row, col, n))
			{
				arr[row][col] = 'Q';
				checkQueen(ans, arr, row + 1, n);
				arr[row][col] = '.';
			}
		}
	}

	bool isSafe(vector<string> &arr, int r, int c, int n)
	{
		for (int k = 0; k < n; k++)
		{
			if (arr[r][k] == 'Q' || arr[k][c] == 'Q')
			{
				return false;
			}
		}
		for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
		{
			if(arr[i][j]=='Q')
                return false;
		}
		for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
		{
			if(arr[i][j]=='Q')
                return false;
		}
        return true;
	}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>arr(n,string(n,'.'));
        checkQueen(ans,arr,0,n);
		return ans;
    }
};