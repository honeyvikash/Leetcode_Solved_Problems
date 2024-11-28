class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        deque<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        q.push_front({0, 0});
        dist[0][0] = 0;

        
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop_front();

            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                    int new_dist = dist[row][col] + grid[nrow][ncol];

                    if(new_dist<dist[nrow][ncol]){
                        dist[nrow][ncol] = new_dist;

                        if(grid[nrow][ncol]==0){
                            q.push_front({nrow,ncol});
                        }else{
                            q.push_back({nrow,ncol});
                        }
                    }
                }
            }


        }
        return dist[n-1][m-1];
    }
};