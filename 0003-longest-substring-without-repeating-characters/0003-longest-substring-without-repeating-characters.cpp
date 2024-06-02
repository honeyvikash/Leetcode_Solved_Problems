class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[1000]={0};
        int i=0,j=0,ans=0;
        while(j<s.size())
        {
            cnt[s[j]]++;
            while(cnt[s[j]]>1)
            {
                cnt[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;

    }
};