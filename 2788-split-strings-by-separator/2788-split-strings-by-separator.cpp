class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char s) {
        vector<string> ans;
        for(auto &i:words)
        {
            string tmp = i;
            string a = "";
            int p = 0;
            while(p<tmp.size())
            {
                if(p<tmp.size() && tmp[p]==s)
                {
                    if(a.size()>0)
                    ans.push_back(a);
                    a="";
                    p++;
                }
                else
                {
                    a+=tmp[p++];
                }
            }
            if(a.size()>0)
                ans.push_back(a);
        }
        return ans;
    }
};