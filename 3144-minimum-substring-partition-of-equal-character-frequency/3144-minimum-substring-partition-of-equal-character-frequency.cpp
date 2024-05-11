class Solution {
public:
    int minimumSubstringsInPartition(string s) 
    {
        vector<int>dp(s.size()+1);
        dp[0]=0;
        for(int i=0;i<s.size();i++)
        {
            dp[i+1]=i+1;
            vector<int>vec(26,0);
            for(int j=i;j>=0;j--)
            {
                vec[s[j]-'a']++;
                bool flag=true;
                for(int k=0;k<26;k++)
                {
                    if(vec[k]!=0 and vec[k]!=vec[s[j]-'a'])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    dp[i+1]=min(dp[i+1],1+dp[j]);
                }
            }
        }
        return dp[s.size()];
    }
};