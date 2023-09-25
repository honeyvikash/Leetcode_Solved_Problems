class Solution {
public:
    char findTheDifference(string s, string t) {
          unordered_map<char,int> hm;
          if (s.size()==0) return t[0];
          for (int i=0;i<s.size();i++)
          {
              hm[s[i]]++;
          }
          for (auto x:t)
          {
              if (hm.find(x) != hm.end())
              {
                  if (hm[x]==0)
                  {
                      return x;
                  }
                  hm[x]--;                  
              }
              else
                return x;  
          }
        return ' ';  
    }
};