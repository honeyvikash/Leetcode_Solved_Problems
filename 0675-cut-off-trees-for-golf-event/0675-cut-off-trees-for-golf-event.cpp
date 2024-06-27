class Solution {
public:
    int bfs(int x1 , int y1 , int x2 , int y2 , vector<vector<int>>& forest)
    {
        int n = forest.size() ;
        int m = forest[0].size() ;

        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<pair<int,int>> q ;
        q.push({x1,y1});
        vis[x1][y1]=1 ;

        int dx[]={-1,0,0,1} ;
        int dy[]={0,-1,1,0} ;

        int steps = 0 ;
        while(!q.empty())
        {
            int sz = q.size() ;
            while(sz--)
            {
                auto it = q.front() ;
                q.pop() ;

                int x = it.first ; 
                int y = it.second ;

                if(x==x2 && y==y2) return steps ;

                for(int i=0 ; i<4 ; i++)
                {
                    int nrow = x+dx[i] ;
                    int ncol = y+dy[i] ;

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                    {
                        if(forest[nrow][ncol]>0 && !vis[nrow][ncol])
                        {
                            q.push({nrow,ncol});
                            vis[nrow][ncol]=1 ;
                        }
                    }
                }
            }
            steps++ ;
        }

        return -1 ;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int,pair<int,int>>> trees ;

        int n = forest.size() ;
        int m = forest[0].size() ;

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(forest[i][j]>1)
                {
                    trees.push_back({forest[i][j],{i,j}});
                }
            }
        }

        sort(trees.begin(),trees.end());

        if(trees[0].second.first!=0 || trees[0].second.second!=0)
        {
            trees.insert(trees.begin(),{0,{0,0}});
        }

        int ans = 0 ;
        for(int i=1 ; i<trees.size() ; i++)
        {
            auto src = trees[i-1].second ; 
            auto dest = trees[i].second ; 

            int x1 = src.first , y1=src.second ;
            int x2 = dest.first , y2=dest.second ;

            int cnt = bfs(x1,y1,x2,y2,forest);

            if(cnt==-1) return -1 ;

            ans+=cnt ;
        }

        return ans ;
    }
};