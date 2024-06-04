class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        bool ans=false;
        for(auto &i:s)
        {
            m[i]++;
        }
        int odd=0,even=0,cnt=0;
        for(auto &x:m)
        {
            if((x.second)%2!=0)
            {
                odd+=(x.second)-1;
                 ans=true;
            }
            else
            {
                even+=x.second;
            }
        }
        cnt=odd+even;
        if(ans)
        {
            cnt+=1;
        }
        return cnt;
    }
};