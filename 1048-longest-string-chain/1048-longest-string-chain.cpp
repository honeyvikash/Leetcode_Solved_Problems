class Solution {
public:
    static bool comp(string& a,string& b)
    {
        if(a.size()>b.size())
        return false;
        else if(a.size()<b.size())
        return true;
        else
        {
            for(int i=0;i<a.size();i++)
            {
                if(a[i]<b[i])
                return true;
                else if(a[i]>b[i])
                return false;
            }
            return true;
        }
    }
    bool isValid(string a,string b)
    {
        if(a.size()>b.size())
        swap(a,b);
        int n1 = a.size();
        int n2 = b.size();
        int i = 0,j = 0;
        while(i<n1 && j<n2)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            j++;
        }
        if(i>=n1 && (n2-n1)==1)
        {
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isValid(words[j],words[i]))
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};