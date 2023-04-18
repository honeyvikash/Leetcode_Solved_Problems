class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int m=s1.size();
   int n=s2.size();
   
   string s3;
   int c1=0,c2=0;
   
       for(int i=0;i<m+n;i++)
       {
            if(c1==(m) && c2==(n))
           {
               break;
           }
           if(c1<m)
           {
               s3.push_back(s1[i]);
               c1++;
           }
           if(c2<n)
           {
               s3.push_back(s2[i]);
               c2++;
           }
       }
   return s3;
    }
};