class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& a, ll t) {
        set<vector<int>>st;
        sort(a.begin(),a.end());
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ll req=t-a[i]-a[j];
                int s=j+1,e=n-1;
                while(s<e)
                {
                    ll mid = a[s]+a[e];
                    if(mid>req)e--;
                    else if(mid<req)s++;
                    else
                    {
                        st.insert({a[i],a[j],a[s],a[e]});
                        s++;
                        e--;
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};