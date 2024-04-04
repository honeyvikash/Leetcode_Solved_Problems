class Solution {
public:
    int maxDepth(string s) {
        int o=0,maxiDepth=0;
        for(auto &x:s)
        {
            if(x=='(')o++;
            if(x==')')o--;
            maxiDepth=max(maxiDepth,o);
        }
        return maxiDepth;
    }
};