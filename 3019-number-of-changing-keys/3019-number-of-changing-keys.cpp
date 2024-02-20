class Solution {
public:
    int countKeyChanges(string s) {
        // int n = s.size(), ans = 0;
        
//         for(int i = 0; i < n; i++)
//         {
//             if(s[i] >= 'A' && s[i] <= 'Z')
//                 s[i] = 'a' + s[i] - 'A';
//         }
        
//         for(int i = 1; i < n; i++)
//         {
//             if(s[i] != s[i-1]) ans++;
//         }
        
//         return ans;
        int n = s.size(), ans = 0;
        for (int i = 0; i + 1 < n; i++) if (tolower(s[i]) != tolower(s[i+1])) ans++;
        return ans;
    }
};