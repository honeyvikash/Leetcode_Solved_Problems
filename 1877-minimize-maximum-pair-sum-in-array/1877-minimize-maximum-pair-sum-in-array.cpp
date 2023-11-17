class Solution {
public:
    int minPairSum(vector<int>& a) {
        sort(a.begin(),a.end());
        int maxi = 0;
        int n = a.size();
        for(int i=0;i<n/2;i++)
        {
            maxi = max(maxi,a[i]+a[n-i-1]);
        }
        return maxi;
    }
};