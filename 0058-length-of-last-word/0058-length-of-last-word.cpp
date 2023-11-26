class Solution {
public:
    int lengthOfLastWord(string s) {
        string word;
        stringstream str(s);
        int ans = 0;
        while(str>>word){
            ans = word.size();
        }
        return ans;
    }
};