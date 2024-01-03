class Solution {
public:
    int numberOfBeams(vector<string>& a) {
        int n=a.size();
        int m=a[0].size();
        int cnt=0,ans=0,prev=0;
        for(int i=0;i<n;i++)
        {
            cnt=0;
            bool check=false;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='1')
                {
                    cnt++;
                    check=true;
                }
            }
            if(check)
            {
                ans+=(cnt*prev);
                prev=cnt;
            }
        }
        return ans;
    }
};