class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0,cnt0 = 0;
        for(auto &i:s)
        {
            if(i=='0')
                cnt0++;
            else
                cnt1++;
        }
        string ans = "";
        while(cnt1>1)
        {
            ans+='1';
            cnt1--;
        }
        while(cnt0>0)
        {
            ans+='0';
            cnt0--;
        }
        ans+='1';
        return ans;
    }
};