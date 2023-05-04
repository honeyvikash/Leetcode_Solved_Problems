class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        bool check=false;
        for(int i=0;i<strs[0].size();i++)
        {
            char c = strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(c!=strs[j][i])check=true;
            }
            if(!check)ans.push_back(c);
            else break;
        }
        return ans;
    }
};