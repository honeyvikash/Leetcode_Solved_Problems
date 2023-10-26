class Solution {
public:
    #define ll long long
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<ll,ll> m;
        m[arr[0]] = 1;
        for(int i=1;i<n;i++)
        {
            long long cnt = 1;
            for(auto &j:m)
            {
                if(arr[i]%j.first==0 && m.find(arr[i]/j.first)!=m.end())
                {
                    cnt+=j.second*m[arr[i]/j.first];
                }
            }
            m[arr[i]] = cnt;
        }
        int ans = 0;
        for(auto &i:m)
        {
            ans = (ans+i.second)%mod;
        }
        return ans;
    }
};