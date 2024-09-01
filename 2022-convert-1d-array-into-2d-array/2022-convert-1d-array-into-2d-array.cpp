class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        int val = m*n;
        if(original.size() != val) return ans;
        for(int i=0;i<m;i++)
        {
            vector<int> temp;
            for(int j=(i)*n;j<(i+1)*n;j++)
            {
                temp.push_back(original[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};