class Solution {
public:
    string reverseWords(string s) {
        string word, ans="";
        stringstream ss(s); //Created a stringstream object for str
        
        while(ss>>word)
        {
            ans = word + " " + ans;
        }
        ans.pop_back();
        return ans;
    }
};