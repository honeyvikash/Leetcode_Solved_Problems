class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size() ;
        int m = land[0].size() ;

        vector<vector<int>> vis(n,vector<int>(m,0)) ;
        vector<vector<int>> ans ;

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(land[i][j]==1 && !vis[i][j])
                {
                    int row , col ; 
                    vector<int>temp ;
                    temp.push_back(i) ;
                    temp.push_back(j) ;

                    queue<pair<int,int>> q ;
                    q.push({i,j}) ;

                    vis[i][j]=1 ;
                    while(!q.empty())
                    {
                        row = q.front().first ;
                        col = q.front().second ;
                        q.pop() ;

                        if(col+1<m && land[row][col+1]==1 && !vis[row][col+1])
                        {
                            vis[row][col+1]=1 ;
                            q.push({row,col+1});
                        }

                        if(row+1<n && land[row+1][col]==1 && !vis[row+1][col])
                        {
                            vis[row+1][col]=1 ;
                            q.push({row+1,col});
                        }
                    }

                    temp.push_back(row);
                    temp.push_back(col) ;
                    ans.push_back(temp); 
                }
            }
        }

        return ans ;
    }
};