class Solution {
public:
    int scoreOfParentheses(string x) {
        stack<int>s;
        int cnt = 0;
        for(int i=0;i<x.size();i++)
        {            
            char ch=x[i];
            
            if(ch=='(')
            {
                s.push(cnt);
                cnt=0;
            }
            else
            {
                        cnt = s.top() + max(2 * cnt, 1);
                        s.pop();
            }
        }
        return cnt;
    }
};