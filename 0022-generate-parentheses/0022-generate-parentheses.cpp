class Solution {
public:
    void solve(int c, int o,string &op, vector<string>&v)
    {
        if(o==0 && c==0)
        {
            v.push_back(op);
            return ;
        }
        if(o!=0)
        {
            string op1=op;
            op1.push_back('(');
            solve(c,o-1,op1,v);
        }
        if(c>o)
        {
            string op2=op;
            op2.push_back(')');
            solve(c-1,o,op2,v);
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int c=n,o=n;
        string op="";
        solve(c,o,op,ans);
        return ans;
    }
};