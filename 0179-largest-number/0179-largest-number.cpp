class Solution {
public:
    static bool comp(string s1,string s2)
    {
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& a) {
        vector<string>v;
        for(auto &x:a)
        {
            string p=to_string(x);
            v.push_back(p);
        }
        sort(v.begin(),v.end(),comp);
        if(v[0]=="0") return "0";
        string ans="";
        for(auto &x:v)
        {
            ans+=x;
        }
        return ans;
    }
};