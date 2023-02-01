class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
      vector<int>ind;
      vector<int>ans;
      for(int i=0;i<s.size();i++)  
      {
          if(s[i]==c)ind.push_back(i);
      }
      
      for(int i=0;i<s.size();i++)
      {
          int d1=INT_MAX;
          for(int j=0;j<ind.size();j++){
          int d2 = abs(i-ind[j]);
           if(d2<d1)d1=d2;
          }                  
          ans.push_back(d1);
      }
      return ans;
    }
};