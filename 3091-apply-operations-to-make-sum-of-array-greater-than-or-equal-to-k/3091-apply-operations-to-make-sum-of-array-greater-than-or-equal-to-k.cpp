class Solution {
public:
    int minOperations(int k) {
        if(k==1)
        {
            return 0;
        }
        int ans=k;
        for(int i=1;i<=k;i++)
        {
            int dv=(k/i);
            if(k%i)
            {
                dv++;
            }
            ans=min(ans,dv-1+(i-1));
        }
        return ans;
    }
};