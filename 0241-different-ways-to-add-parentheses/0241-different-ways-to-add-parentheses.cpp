class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for(int i=0;i<expression.size();i++)
        {
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*')
            {
                string ls = expression.substr(0,i);
                string rs = expression.substr(i+1);
                vector<int> leftans = diffWaysToCompute(ls);
                vector<int> rightans = diffWaysToCompute(rs);
                
                for(int j=0;j<leftans.size();j++)
                {
                    int a = leftans[j];
                    for(int k=0;k<rightans.size();k++)
                    {
                        int b = rightans[k];
                        if(expression[i]=='+') ans.push_back(a+b);
                        else if(expression[i]=='-') ans.push_back(a-b);
                        else ans.push_back(a*b);
                    }
                }
            }
        }
        if(ans.size()==0) ans.push_back(stoi(expression));
        return ans;
    }
};
