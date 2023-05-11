class Solution {
public:
    #define ll long long
    vector<ll> sumOfThree(ll n) {
        if(n%3!=0)return {};
        
        ll a = n/3;
        ll b = n/3;
        ll c = n/3;
        a++;
        b--;
        return {b,c,a};
    }
};