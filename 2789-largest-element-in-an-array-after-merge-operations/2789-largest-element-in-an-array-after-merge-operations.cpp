class Solution {
public:
#define ll long long
    
    static bool cmp(ll x, ll y) 
    {
        return (x < y);
    }
    
    long long maxArrayValue(vector<int>& a) {
        stack<ll> s;
        ll ans = 0;
        for (int i = a.size() - 1; i >= 0; --i) 
        {
            if (s.empty() || a[i] > s.top()) 
            {
                s.push(a[i]);
            }
            else 
            {
                ll sum = s.top() + a[i];
                s.pop();
                s.push(sum);
            }
            ans = max(ans, s.top());
        }        
        return ans;
    }
};