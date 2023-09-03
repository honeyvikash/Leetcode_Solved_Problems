class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        multiset<char> ms1,ms2,ms3,ms4;
        int n = s1.size();
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                ms1.insert(s1[i]);
            else
                ms2.insert(s1[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                ms3.insert(s2[i]);
            else
                ms4.insert(s2[i]);
        }
        if(ms1==ms3 && ms2==ms4)
            return true;
        return false;
        
    }
};