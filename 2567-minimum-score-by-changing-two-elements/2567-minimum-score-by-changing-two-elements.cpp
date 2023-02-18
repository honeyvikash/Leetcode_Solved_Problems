class Solution {
public:
    int minimizeSum(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        int x1=a[n-3]-a[0];
        int x2=a[n-2]-a[1];
        int x3=a[n-1]-a[2];
        return n==3?0:min({x1,x2,x3});        
    }
};