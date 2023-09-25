class Solution {
public:
    int trap(vector<int>& h) {
        int len = h.size();
        int l[len];
        int r[len];
        l[0]=h[0];
        r[len-1]=h[len-1];
        for(int i=1;i<len;i++)
        {
            l[i]=max(l[i-1],h[i]);
        }
        for(int i=len-2;i>=0;i--)
        {
            r[i]=max(r[i+1],h[i]);
        }
        int ans = 0;
        for(int i=0;i<len;i++)
        {
            ans += min(l[i],r[i])-h[i];
        }
        return ans;
    }
};