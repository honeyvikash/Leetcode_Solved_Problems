class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans_w1="";
        string ans_w2="";
        for(int i=0;i<word1.size();i++)
        {
            ans_w1+=word1[i];
        }
        for(int i=0;i<word2.size();i++)
        {
            ans_w2+=word2[i];
        }
        return ans_w1==ans_w2;
    }
};