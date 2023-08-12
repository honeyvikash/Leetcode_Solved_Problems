class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> fre(26);
        for(auto &i:s)
            fre[i-'a']++;
        for(auto &i:t)
            fre[i-'a']--;
        for(int i=0;i<26;i++)
        {
            if(fre[i]!=0)
                return false;
        }
        return true;
    }
};