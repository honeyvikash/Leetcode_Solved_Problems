class Solution {
public:
    int reinitializePermutation(int n) {
        int ans = 0;
        int i = 1;
        while(ans==0 || i>1)
        {
            if(i<n/2)
            i*=2;
            else
            i = (i-n/2)*2+1;
            ans++;
        }
        return ans;
    }
};