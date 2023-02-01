class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t found = s.find(part);
        int n = part.size();
        while(found != string::npos)
        {
            s.erase(found,n);
            found = s.find(part);
        }
        return s;
    }
};