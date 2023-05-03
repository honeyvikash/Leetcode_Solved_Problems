class Solution {
public:
    #define ll long long
    vector<ll> distance(vector<int>& a) {
        vector<ll>ans(a.size(),0);
        unordered_map<ll,ll>forward_sum,backward_sum,forward_cnt,backward_cnt;
        for(int i=0;i<a.size();i++)
        {
            forward_sum[a[i]]+=i;
            forward_cnt[a[i]]++;
        }
        for(int i=0;i<a.size();i++)
        {
            forward_sum[a[i]]-=i;
            forward_cnt[a[i]]--;

            ans[i]=abs( forward_sum[a[i]] - (1ll*forward_cnt[a[i]]*i))+
                    abs( backward_sum[a[i]] - (1ll*backward_cnt[a[i]]*i));

            backward_sum[a[i]]+=i;
            backward_cnt[a[i]]++;
        }
        return ans;
    }
};