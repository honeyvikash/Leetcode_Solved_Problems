class Solution {
public:
    string ans="";
    int cnt=0;
    string  solve(string &s)
    {
        for(auto &x:s)
        {
            if(x=='(' && cnt++>0)
            {
                ans+=x;
            }
            else if(x==')' && cnt-->1)
            {
                ans+=x;
            }
        }
        return ans;
    }
    string removeOuterParentheses(string s) {
        return solve(s);
    }
};



