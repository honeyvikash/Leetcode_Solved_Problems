class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& v) {
        int start=1,end=1,n=v.size();
        bool flag1=true,flag2=true;
        for (int i=1;i<n;i++) {
            if (flag1 && v[i]>=v[i-1]) {
                start++;
            } else {
                flag1=false;
            }
            if (flag2 && v[n-i-1]<=v[n-i]) {
                end++;
            } else {
                flag2=false;
            }
        }

        if (start==n || end==n) {
            return 0;
        }
        int ans=min(n-start,n-end);

        for (int i=0;i<start;i++) {
            int idx=lower_bound(v.end()-end,v.end(),v[i])-v.begin();
            if (idx!=n) {
                ans=min(ans,idx-i-1);
            }
        }
        return ans;
    }
};