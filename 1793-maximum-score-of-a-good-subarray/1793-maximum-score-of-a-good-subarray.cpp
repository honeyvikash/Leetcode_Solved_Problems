class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        //Greedy
        int n = a.size();
        int i=k,j=k;
        int currmini= a[k];
        int ans = a[k];
        while(i>0 || j<n-1)
        {
            int lv = (i>0)?a[i-1]:0;
            int rv = (j<n-1)?a[j+1]:0;
            
            if(lv<rv)
            {
                j++;
                currmini = min(currmini,a[j]);
            }
            else
            {
                i--;
                currmini = min(currmini,a[i]);
            }
            ans = max(ans,currmini*(j-i+1));
        }
        return ans;
    }
};