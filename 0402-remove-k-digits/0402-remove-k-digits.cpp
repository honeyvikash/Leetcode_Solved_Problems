class Solution {
public:
    string removeKdigits(string s, int k) {
       string ans="";
       int n=s.size();
       for(int i=0;i<n;i++)
       {
           while(ans.size()&&ans.back()>s[i]&&k>0)
           {
               ans.pop_back();
               k--;
           }
           if(ans.size()||s[i]!='0') ans+=s[i];
       }
       while(ans.size()&&k>0)
       {
           ans.pop_back();
           k--;
       }
       return ans.size()?ans:"0";
    }
};