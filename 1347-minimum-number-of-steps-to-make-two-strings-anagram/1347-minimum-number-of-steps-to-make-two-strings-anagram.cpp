class Solution {
public:
    int minSteps(string s, string t) {
        int cnt=0;
        vector<int>freq1(26,0),freq2(26,0);
        for(int i=0;i<s.size();i++)
        {
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            cnt+=abs(freq1[i]-freq2[i]);
        }
        return cnt%2==0?cnt/2:cnt/2+1;
    }
};