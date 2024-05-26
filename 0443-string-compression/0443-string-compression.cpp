class Solution {
public:
    int compress(vector<char>& chars) {
        char ch = chars[0];
        int cnt = 1, ans = 0;
        string compressed = "";
        for(int i = 1; i < chars.size(); i++) 
        {
            if(chars[i] == ch) cnt += 1;
            else 
            {
                compressed += ch;
                if(cnt > 1) compressed += to_string(cnt);
                ch = chars[i];
                cnt = 1;
            }
        }
        compressed += ch;
        if(cnt > 1) compressed += to_string(cnt);
        chars = vector<char>(compressed.begin(), compressed.end());
        return chars.size();
    }
};