class Solution {
public:
    string reversePrefix(string word, char ch) {
        bool flag = false;
        int cnt=1;
        for(auto &i:word)
        {
            if(i==ch)
            {
                flag = true;
                break;
            }
            cnt++;
        }
        if(flag)
        {
            reverse(word.begin(),word.begin()+cnt);
        }
        return word;
    }
};