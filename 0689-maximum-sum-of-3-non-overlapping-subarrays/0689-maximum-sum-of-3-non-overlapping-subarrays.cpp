class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        map<long long,vector<int>>m;
        int n=nums.size();
        vector<long long> pre(n+1);
        for(int i=0;i<n;i++)pre[i+1]=pre[i]+nums[i];
        multiset<long long> mr,ml;
        for(int i=0;i<n-k+1;i++)
        {
            long long sum=0;
            sum=pre[i+k]-pre[i];
            m[sum].push_back(i);
            if(i>=(2*k))mr.insert(sum);
            if(i==0)ml.insert(sum);
        }
        long long mx=0; vector<int> ans(3);
        for(int i=k;i<=n-(2*k);i++)
        {
            long long mid= pre[i+k]-pre[i];
            long long l=*(--ml.end());
            long long r= *(--mr.end());
            if((mid+l+r)>mx)
            {
                mx=mid+l+r;
                ans[0]=m[l][0];
                ans[1]=i;
                int j= lower_bound(m[r].begin(),m[r].end(),i+k)-m[r].begin();
                ans[2]=m[r][j];
            }
            long long x=pre[i+1]-pre[i+1-k],y=pre[i+2*k]-pre[i+k];
            ml.insert(x); mr.erase(mr.find(y));
        }
        return ans;
    }
};