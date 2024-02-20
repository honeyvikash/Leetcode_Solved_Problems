class Solution {
public:
    #define ll long long
    int maximumLength(vector<int>& a) {
        map<ll,ll>m;
        for(auto i:a) m[i]++;
        ll ans = max(1ll,m[1]);
        if(ans%2==0)
            ans--;
        for(auto i:m)
        {
            long long x = i.first;
            if(x==1) continue;
            ll ans1=0;
            while(m.find(x)!=m.end() && m[x]>=2)
            {
                x*=x;
                ans1+=2;
            }
            if(m[x]>0)
                ans1+=1;
            else
                ans1-=1;
            ans=max(ans,ans1);
        }
        return ans;
    }
};