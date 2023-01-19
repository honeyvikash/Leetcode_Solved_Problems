class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int planted=0;
        for(int i=0;i<f.size() && planted<n;i++)
        {
            if(f[i]==0)
            {
                int nxt=(i==f.size()-1)?0:f[i+1];
                int pre=(i==0)?0:f[i-1];
                if(pre==0 && nxt==0)
                {
                    planted++;
                    f[i]=1;
                }
            }
        }
        return planted==n;
    }
};