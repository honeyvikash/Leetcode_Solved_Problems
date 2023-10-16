class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cp) {
        unordered_map<string,int> m;
        for(auto &i:cp)
        {
            int num = stoi(i);
            int len = i.size();
            int k = 0;
            while(k<len && i[k]!=' ')
            {
                k++;
            }
            k++;
            m[i.substr(k,len)]+=num;
            while(k<len)
            {
                while(i[k]!='.' && k<len) k++;
                
                k++;
                if(k<len)
                {
                    string tmp = i.substr(k,len);
                    m[tmp]+=num;
                }
            }
        }
        vector<string> ans;
        for(auto &i:m)
        {
            string tmp = to_string(i.second);
            tmp+=' ';
            tmp+=i.first;
            ans.push_back(tmp);
        }
        return ans;
    }
};