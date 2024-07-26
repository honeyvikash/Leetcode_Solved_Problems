class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Floyd-Warshall algorithm
        vector<vector<int>> mat(n,vector<int>(n,10001));
        for(int i = 0;i<n;i++)
        {
            mat[i][i] = 0;
        }
        for(int i = 0;i<edges.size();i++)
        {
            int a = edges[i][0], b = edges[i][1], w = edges[i][2];
            mat[a][b] = w;
            mat[b][a] = w;
        }

        for(int k = 0;k<n;k++)
        {
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        vector<int> sol(n,0);
        for(int i = 0;i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                if(mat[i][j] <= distanceThreshold)
                {
                    sol[i]++;
                    sol[j]++;
                }
            }
        }

        int dis = INT_MAX, ret;
        for(int i = 0;i<n;i++)
        {
            if(sol[i] < dis)
            {
                dis = sol[i];
                ret = i;
            }
            if(sol[i] == dis)
            {
                ret = max(i, ret);
            }
        }

        return ret;
    }
};