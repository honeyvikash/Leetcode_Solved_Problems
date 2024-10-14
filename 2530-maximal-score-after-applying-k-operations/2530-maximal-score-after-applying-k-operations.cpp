class Solution {
public:
    #define all(a) (a).begin(), (a).end()
    #define ll long long int
    long long maxKelements(vector<int>& a, int k) {
        priority_queue<ll>p(all(a));
        ll s=0;
        while(k--)
        {
            ll t=p.top();
            // cout<<s<<endl;
            p.pop();
            s+=t;
            ll newt=ceil(t/(3*1.0));
            p.push(newt);
        }
        return s;
    }
};