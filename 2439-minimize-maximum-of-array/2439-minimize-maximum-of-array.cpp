class Solution {
public:
    #define ll long long
    int minimizeArrayValue(vector<int>& a) {
        ll sum = a[0];
        ll ans=a[0];
        for(int i=1;i<a.size();i++)
        {
            sum+=a[i];
            ll t = ceil((sum*1.0)/(i+1));
            ans=max(ans,t);
        }
        return (int)ans;
    }
};