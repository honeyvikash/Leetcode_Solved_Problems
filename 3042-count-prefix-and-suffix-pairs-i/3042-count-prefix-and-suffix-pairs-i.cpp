class Solution {
public:
    int f(string a, string b)
    {
        if(a.size()>b.size()) return 0;
        string pb=b.substr(0,(int)a.size());
        string sb=b.substr(int(b.size())-int(a.size()));
        // cout<<a<<" "<<pb<<" "<<sb<<endl;
        if(a==pb && a==sb) return 1;
        return 0;
    }
    int countPrefixSuffixPairs(vector<string>& w) {
        int n=w.size();
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                string a=w[i];
                string b=w[j];
                ans+=f(a,b);
            }
        }
        return ans;
    }
};