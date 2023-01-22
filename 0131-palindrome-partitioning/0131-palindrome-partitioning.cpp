class Solution {
public:
    vector<vector<string>> ans;
    
    bool palindrome(string s)
    {
        if(s.size()==0) return true;
        int len = s.size();
        for(int i=0; i<len; i++) if(s[i]!= s[len-1-i]) return false;
        return true;
    }

    void compute(vector<string> &temp, string s, int index)
    {
        if(index == s.size())  ans.push_back(temp);
        else{
            string substr1;
            for(int i=index; i<s.size(); i++)
            {
                substr1 += s[i];
                if(substr1[0] != s[i]) continue;
                if(palindrome(substr1)){
                    temp.push_back(substr1);
                    compute(temp, s, i+1);
                    temp.pop_back();
                }
            }    
        } 
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        compute(temp, s, 0);
        return ans;
    }
};