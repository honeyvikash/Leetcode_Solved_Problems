class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ma = 0;
        vector<int> c(26,0);
        int ans = 0;
        int j = 0;
        // char ma_c = '$';
        for(int i =0;i<s.size();i++){
            c[s[i]-'a']++;
            bool b =0;
            for(int i=0;i<26;i++){
                if(c[i]>=k){
                    b = 1;
                    break;
                }
            }
            while(b){
                c[s[j]-'a']--;
                j++;
                int count = 0;
                for(int i=0;i<26;i++){
                    if(c[i]>=k) count++;
                }
                if(count==0){
                    j--;
                    c[s[j]-'a']++;
                    break;
                }
            }
            if(b)ans += j+1;
        }
        return ans;
    }
};