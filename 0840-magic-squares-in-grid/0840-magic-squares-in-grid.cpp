class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int i1 = 0;
        int i2 = 2;
        
        int ans = 0;
        while(i2<grid.size()){
            int j1 = 0;
            int j2 = 2;
            
            while(j2<grid[0].size()){
                vector<int> temp(10,0);
                int r1=0,r2=0,r3=0,c2=0,c3=0,c1=0,d1=0,d2=0;
                for(int i=i1;i<=i2;i++){
                    for(int j=j1;j<=j2;j++){
                        if(i == i1){
                            r1+=grid[i][j];
                        }
                        else if(i == i1+1) r2 += grid[i][j];
                        else if(i == i2) r3 += grid[i][j];

                        if(j == j1) c1+=grid[i][j];
                        else if(j == j1+1) c2 += grid[i][j];
                        else if(j == j2) c3 += grid[i][j];

                        if(grid[i][j] > 0 && grid[i][j] < 10) temp[grid[i][j]]++;
                    }
                }

                int c = 0;
                for(int i=1;i<10;i++){
                    if(temp[i] >= 1) c++;
                }

                if(c != 9){
                    j1++;
                    j2++;
                    continue;
                }

                d1 = grid[i1][j1] + grid[i1+1][j1+1] + grid[i2][j2];
                d2 = grid[i2][j1] + grid[i2-1][j1+1] + grid[i1][j2];
                if(c == 9 && d1 == d2 && c1 == c2 && c2 == c3 && c1 == c3 && r1 == r2 && r2 == r3 && r1 == r3 && c1 == r1 && r1 == d1 && r1 == 15){
                    ans++;
                }

                j1++;
                j2++;
            }

            i1++;
            i2++;
        }

        return ans;
    }
};