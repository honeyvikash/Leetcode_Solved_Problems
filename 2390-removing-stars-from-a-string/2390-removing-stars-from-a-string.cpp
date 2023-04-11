class Solution {
public:
    string removeStars(string s) {
        string ans="";
        for(auto &x:s)
        {
            if(ans.size()!=0 && x=='*')
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(x);
            }

        }
        return ans;
    }
};