class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int n = a.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            long long tmp = 1LL;
            int j = i;
            while(j<n)
            {
                tmp *= a[j];
                if(tmp<k)cnt++;
                j++;
                if(tmp>=k)break;
            }
        }
        return cnt;
    }
};