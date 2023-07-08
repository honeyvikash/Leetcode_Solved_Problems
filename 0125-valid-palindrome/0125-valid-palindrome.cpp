class Solution {
public:
    string removeSpaces(string str)
    {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        return str;
    }
    string removePunctuations(std::string& s) {
    std::string result = "";
    for (char c : s) {
        if (!ispunct(c)) { // If c is not a punctuation character
            result += c;
        }
    }
    s = result;
    return s;
    }
    
    bool isPalindrome(string s) 
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s=removePunctuations(s);
        s=removeSpaces(s);
        int cnt=0;
        if(s.length()==1 || s.length()==0){return cnt=1;}
        else
        {
            for(int i=0;i<s.length()/2;i++)
            {
                if(s[i]!=s[s.length()-i-1])
                {
                    cnt=0;
                    break;
                }
                else{
                    cnt=1;
                }
            }
        }
        return cnt;
    }
        
};