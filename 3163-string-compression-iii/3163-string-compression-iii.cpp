class Solution {
public:
    string compressedString(string word) {
        int curr = 1;
        char last = word[0];
        string ans;
        for(int i=1;i<word.size();i++)
        {
            if(word[i]==last && curr+1<10)
            {
                curr++;
            }
            else
            {
                ans+=to_string(curr);
                ans.push_back(last);
                curr=1;
                last=word[i];
            }
        }
        if(curr>0)
        {
            ans+=to_string(curr);
            ans.push_back(last);
        }
        return ans;
    }
};