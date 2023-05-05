class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        vector<int> pref(n);
        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i]))
            pref[i] = 1;
        }
        for(int i=1;i<n;i++)
        {
            pref[i]+=pref[i-1];
        }
        int ans = 0;
        ans = max(ans,pref[k-1]);
        for(int i=k;i<n;i++)
        {
            ans = max(ans,pref[i]-pref[i-k]);
        }
        return ans;
    }
};