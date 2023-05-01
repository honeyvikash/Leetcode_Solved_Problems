class Solution {
public:
    double average(vector<int>& s) {
        sort(s.begin(),s.end());
        int n=s.size();
        long long ans=accumulate(s.begin(),s.end(),0);
        ans=ans-s[0]-s[n-1];
        double res=(ans/((n-2)*1.0));
        return res;
    }
};