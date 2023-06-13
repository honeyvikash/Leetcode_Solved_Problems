class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        unordered_set<int>s;
        int res =0;
        for(int i=0;i<n;i++)
        {
            s.insert(a[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(s.find(a[i]-1)==s.end())
            {
               int curr=1;
               while(s.find(a[i]+curr)!=s.end()) curr++;
                
               res = max(curr,res);
            }
            
        }
        return res;
    }
};