class Solution {
public:
     void helper(int ind ,unordered_set<string>st, string s,
    string sentence, vector<string> &res)
    {
         if(ind==s.size())
         {
             res.push_back(sentence);
             return;
         }

         string temp="";
         for(int i=ind ; i<s.size() ; i++)
         {
            temp+=s[i];
            if(st.count(temp))
            {
               if(sentence.size()==0) helper(i+1,st,s,sentence+temp,res);
                else helper(i+1,st,s,sentence+' '+temp,res);
            }
         }
        return ; 
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n =s.size();
        vector<int>dp(n+1,-1);
        unordered_set<string>st;
        string sentence="";
        vector<string> res;
        for(auto it : wordDict)
        {
            st.insert(it);
        }
        helper(0,st,s,sentence,res);
        return res ;
    }
};