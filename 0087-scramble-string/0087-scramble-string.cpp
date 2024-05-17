class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string a, string b) {
        if(a.size() < 1) return false;
        if(a.compare(b) == 0) return true;
        
        string temp = a + " " + b;
        if(mp.find(temp) != mp.end()){
            return mp[temp];
        }
            
        bool flag = false;
        int n = a.size();
        
        for(int i=1;i<=n-1;i++)
        {
            if(isScramble(a.substr(0,i),b.substr(0,i)) && isScramble(a.substr(i),b.substr(i)))
            {
                flag = true;
                break;
            }
        
            if(isScramble(a.substr(0,i),b.substr(n-i)) && isScramble(a.substr(i),b.substr(0,n-i)))
            {
                flag = true;
                break;
            }
        }
        return mp[temp] = flag;
    }
};