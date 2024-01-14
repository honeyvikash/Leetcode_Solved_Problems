class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> sv,asv;
        string tmp = "";
        for(auto &a:s)
        {
            if(a!=' ')
                tmp += a;
            else
            {
                if(!tmp.empty())
                {
                    sv.push_back(tmp);
                    tmp = "";
                }
            }

        }
        if(!tmp.empty())
        {
            sv.push_back(tmp);
            tmp = "";
        }
        int ml = 0;
        int ni = sv.size();
        for(auto &a:sv)
        {
            ml = max(ml,(int)a.length());
        }
        
        for(int i = 0 ; i < ml ; ++i)
        {
            string tmp = "";
            for(int j = ni-1 ; j >= 0 ; --j)
            {
                if(i>=sv[j].size())
                {
                    if(!tmp.empty())
                        tmp+=" ";
                }
                else
                    tmp+=sv[j][i];
            }
            reverse(tmp.begin(),tmp.end());
            asv.push_back(tmp);
        }
        return asv;
    }
};