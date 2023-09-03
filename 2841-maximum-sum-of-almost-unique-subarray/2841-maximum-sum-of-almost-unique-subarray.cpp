class Solution {
public:
    #define ll long long
    ll maxSum(vector<int>& a, int m, int k) {
        ll ans = 0;
        int i = 0,j = k;
        long long sum = 0;
        map<int,int> ma;
        for(int i=0;i<k;i++)
        {
            sum+=a[i];
            ma[a[i]]++;
        }
        if(ma.size()>=m)
            ans = sum;
        int n = a.size();
        while(j<n)
        {
            sum-=a[i];
            ma[a[i]]--;
            if(ma[a[i]]==0)
                ma.erase(a[i]);
            i++;
            sum+=a[j];
            ma[a[j]]++;
            if(ma.size()>=m)
                ans = max(ans,sum);
            j++;
        }
        return ans;
    }
};