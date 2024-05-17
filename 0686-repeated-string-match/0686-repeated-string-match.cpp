class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = b.size()/a.size();
        int ans=1;
        string s=a;
        for(int i=0;i<count+2;i++)
        {
             if (s.find(b) != std::string::npos)
                return ans;
            s+=a;
            ans++;
        }
        return -1;
    }
};