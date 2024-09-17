class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>v1,v2;
        stringstream ss1(s1);
        string e1;
        while(ss1>>e1)
        {
            v1.push_back(e1);
        }
        stringstream ss2(s2);
        string e2;
         while(ss2>>e2)
        {
            v2.push_back(e2);
        }
        unordered_map<string,int>m;
        for(auto &x:v1)m[x]++;
        for(auto &x:v2)m[x]++;
        vector<string>ans;
        for(auto &x:m)
        {
            if(x.second==1)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
        

    }
};