class Solution {
public:
    int numberOfPairs(vector<vector<int>>& a) {
        int n=a.size();
        int ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if(i==j)continue;
                
                int x=a[i][0];
                int y=a[i][1];
                int x1=a[j][0];
                int y1=a[j][1];
                if (x1>=x && y>=y1)
                {
                    bool found=true;
                    for (int d=0;d<n;d++)
                    {
                        if (d==i || d==j)
                        {
                            continue;
                        }
                        int x2=a[d][0];
                        int y2=a[d][1];
                        if (x2>=x && x2<=x1 && y2>=y1 && y2<=y)
                        {
                            found=false;
                            break;
                        }
                    }
                    ans+=found;
                }
            }
        }
        return ans;
    }
};