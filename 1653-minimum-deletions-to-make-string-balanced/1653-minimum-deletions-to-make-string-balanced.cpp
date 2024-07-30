class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        if(n==1) return 0;
        vector<int> cntb(n,0),cnta(n,0);
        if(s[0]=='b') cntb[0] = 1;
        if(s[n-1]=='a') cnta[n-1] = 1;

        for(int i=1;i<n;i++)
        {
            if(s[i]=='b')
            {
                cntb[i] = cntb[i-1]+1;
            }
            else
            {
                cntb[i]=cntb[i-1];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='a')
            {
                cnta[i] = cnta[i+1]+1;
            }
            else
            {
                cnta[i]=cnta[i+1];
            }
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<cntb[i]<<" ";
        // }cout<<endl;

        // for(int i=0;i<n;i++){
        //     cout<<cnta[i]<<" ";
        // }cout<<endl;
        
        int mini = min(cnta[0], cntb[n - 1]);
        for(int i=0;i<n-1;i++)
        {
            mini = min(mini,cntb[i]+cnta[i+1]);
        }

        return mini;
    }
};