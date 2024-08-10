class Solution {
private:
    void bfs(vector<vector<int>>&graph, int i, int j, int n,vector<vector<int>>&vis)
    {
        queue<pair<int, int>>q;
        q.push({i,j});
        vis[i][j] = 1;
        int nRow[] = { -1, 0, 1,  0};
        int nCol[] = { 0,  -1,  0, 1 };
        
        while(!q.empty())
        {
            pair<int, int>p = q.front();
            int row = p.first;
            int col = p.second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int r = row + nRow[i];
                int c = col + nCol[i];
                
                if(r>=0 && r<n && c>=0 && c<n)
                {
                   if(vis[r][c] == 0 && graph[r][c] == 0)
                   {
                    q.push({r,c});
                    vis[r][c] = 1;
                   }
                }
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {

        int ans = 0;
        int n = grid.size();

        int size = 3*n;

        vector<vector<int>>graph(3*n, vector<int>(3*n, 0));
        int col = 0;

        for(int i=0; i<n; i++)
        {
            string s = grid[i];
            int row = 0;

            for(int j=0; j<s.size(); j++)
            {
                int p = col;

                if(s[j] == ' ')
                {
                    row = row+3;
                    continue;
                }

                else if(s[j] == '/')
                {
                    for(int l=row+2; l>=row; l--)
                    {
                        graph[p][l] = 1;
                        p++;
                    }
                }
                else if(s[j] == '\\')
                {
                    for(int l=row; l<=row+2; l++)
                    {
                        graph[p][l] = 1;
                        p++;
                    }
                }
                row = row+3;
            }
            col = col+3;
        }

        vector<vector<int>>vis(size, vector<int>(size, 0));

        for(int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
            {
                if(graph[i][j] == 0 && vis[i][j] == 0)
                {
                    ans++;
                    bfs(graph, i, j, size, vis);
                }
            }
        }

        return ans;
    }
};