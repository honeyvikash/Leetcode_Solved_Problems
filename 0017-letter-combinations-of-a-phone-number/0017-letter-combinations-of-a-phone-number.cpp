class Solution {
public:
    vector<string> ans;
    void solve(int idx,string& dig,string& ds,map<char,vector<char>>&m)
    {
        if(idx>=dig.size())
        {
            if(ds.size()==dig.size() && ds.size()>0)
            ans.push_back(ds);
            return;
        }
        for(auto i:m[dig[idx]])
        {
            ds+=i;
            solve(idx+1,dig,ds,m);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> m;
        m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r','s'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y','z'};
        string ds = "";
        solve(0,digits,ds,m);
        return ans;
    }
};