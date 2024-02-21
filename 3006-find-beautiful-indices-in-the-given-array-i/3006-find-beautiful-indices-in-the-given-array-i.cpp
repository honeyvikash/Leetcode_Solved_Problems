class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> x;
        vector<int> y;
        int n=s.size();
        int n1=a.size();
        int n2=b.length();
        for(int i=0;i<=n-n1;i++)
        {
            int j=0;
            while(j<n1)
            {
                if(s[i+j]!=a[j])
                    break;
                j++;
            }
            if(j==n1)
                x.push_back(i);
        }
         for(int i=0;i<=n-n2;i++)
        {
            int j=0;
            while(j<n2)
            {
                if(s[i+j]!=b[j])
                    break;
                j++;
            }
            if(j==n2)
                y.push_back(i);
        }
                vector<int> ans;

        if(y.size()==0 || x.size()==0)
            return ans;
        for(int i=0;i<x.size();i++)
        {
            int z=lower_bound(y.begin(),y.end(),x[i])-y.begin();
            if(z==y.size())
                z--;
            if(abs(y[z]-x[i])<=k)
                ans.push_back(x[i]);
            else
            {
                if(z!=0)
                {
                    if(abs(y[z-1]-x[i])<=k)
                        ans.push_back(x[i]);
                }
            }
        }
        return ans;
    }
};