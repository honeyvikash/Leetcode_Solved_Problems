class Solution {
public:
    string mostCommonWord(string p, vector<string>& b) {
        unordered_map<string,int> m1;
        string ans;
        int count=0;
        for(int i=0; i<p.size();)
        {
            string s1="";
            while(i<p.size() && isalpha(p[i]))
            s1.push_back(tolower(p[i++]));
            while(i<p.size() && !isalpha(p[i]))
            i++;
            m1[s1]++;
        }

        for(auto &x: b)m1[x]=0;
        for(auto &x: m1)
        {
            if(count<x.second)
            {
                count=x.second;
                ans = x.first;
            }
        }

        return ans;
    }
};