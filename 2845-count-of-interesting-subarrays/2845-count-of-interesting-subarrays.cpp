class Solution {
public:
    #define ll long long
    ll countInterestingSubarrays(vector<int>& a, int mod, int k) {
        ll ans = 0;
        unordered_map<int,int> fre;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]%mod==k)
                a[i] = -1;
        }
        vector<ll> pref(n);
        if(a[0]==-1)
            pref[0] = 1;
        
        for(int i=1;i<n;i++)
        {
            if(a[i]==-1)
                pref[i] = pref[i-1]+1;
            else
                pref[i] = pref[i-1];
        }
        
        for(int i=0;i<n;i++)
        {
            if(pref[i]%mod==k)
            ans++;
            ll tmp = (pref[i]+mod-k)%mod;
            if(fre.find(tmp)!=fre.end())
            ans+=fre[tmp];
            fre[pref[i]%mod]++;
        }
        return ans;
    }
};