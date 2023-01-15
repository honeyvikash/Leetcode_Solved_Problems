class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=0;
        int current=1;
        int prev=0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i-1]==s[i])current++;
            else
            {
                cnt+=min(current,prev);
                prev=current;
                current=1;
            }
        }
        // as last wale pe bach gya tha
        cnt+=min(current,prev);
        return cnt;
    }
};