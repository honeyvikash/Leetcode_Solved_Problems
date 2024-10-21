class Solution {
public:
    void solve(int ind, unordered_set<string>&st, string &s, int n, int &len){
        if(ind == n){
            if(st.size() > len) len = st.size();
            return;
        }
        for(int i = ind; i < n ; i++){
            if(st.find(s.substr(ind, i-ind+1)) == st.end()){
                st.insert(s.substr(ind, i-ind+1));
                solve(i+1, st, s, n, len);
                st.erase(s.substr(ind, i-ind+1));
            }
        }
    }
    int maxUniqueSplit(string s) {
        int n = s.size();
        unordered_set<string>st;
        int len = 0;
        solve(0, st, s, n, len);
        return len;
    }
};