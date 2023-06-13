class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>,int> r,c;
        for(int i=0;i<n;i++)
        {
            vector<int> tmp;
            for(int j=0;j<n;j++)
            {
                tmp.push_back(grid[i][j]);
            }
            r[tmp]++;
        }
        for(int j=0;j<n;j++)
        {
            vector<int> tmp;
            for(int i=0;i<n;i++)
            {
                tmp.push_back(grid[i][j]);
            }
            c[tmp]++;
        }
        int ans = 0;
        for(auto &i:r)
        {
            if(c.find(i.first)!=c.end())
            {
                ans+=(i.second)*c[i.first];
            }
        }
        return ans;
    }
};