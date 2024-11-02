class Solution {
public:
    bool isCircularSentence(string s) {
        vector<int>space_idx;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')space_idx.push_back(i);
        }
        if(space_idx.size()==0)
        {
            if(s[0]!=s[s.size()-1])
            {
                return false;
            }
            return true;
        }
        for(int i=0;i<space_idx.size();i++)
        {
            if(s[space_idx[i]-1]!=s[space_idx[i]+1])return false;
        }
        //Take Care
        //  Uppercase and lowercase English letters are considered different.
        // failing test case---> "Leetcode eisc cool"
        if(s[0]!=s[s.size()-1])return false;
        return true;
    }
};