class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int>st;
        for (int i = 0; i < tokens.size(); i++)
        {
            int n = tokens[i].size();
            if ('0' <= tokens[i][n - 1] && '9' >= tokens[i][n - 1])
            {
                int number = (stoi)(tokens[i]);
                st.push(number);
            }
            else
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                char c = tokens[i][0];
                switch (c)
                {
                    case '+':
                        st.push(n2 + n1);
                        break;
                    case '-':
                        st.push(n2 - n1);
                        break;
                    case '*':
                        st.push(n2 * n1);
                        break;
                    case '/':
                        st.push(n2 / n1);
                        break;
                }
            }
        }
        return st.top();
    }
};