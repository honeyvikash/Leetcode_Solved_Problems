class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> st(bannedWords.begin(),bannedWords.end());
        int co = 0 ;
        for(string s: message){
            if(st.find(s)!=st.end())co++;
        }
        return co>=2;
    }
};