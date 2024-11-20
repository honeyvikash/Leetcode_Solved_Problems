class Solution {
public:
        
    bool isAllGood(int *hash, int k){
        return hash[0] >= k && hash[1] >= k && hash[2] >= k;
    }
    
    int takeCharacters(string s, int k) {
        // now the question is to find the largest sliding window, such that, count of a,b and c (which is not a part of window) is still > k
        int hash[3] = {0};
        for(int i=0; i<s.size(); i++){
            hash[s[i]-'a']++;
        }

        if(isAllGood(hash,k) == false) return -1;
        
        int start=0;
        int Ans = 0;
        for(int i=0; i<s.size(); i++){
            hash[s[i]-'a']--;
            while(isAllGood(hash, k) == false){
                hash[s[start++]-'a']++;
            }
            Ans = max(Ans, i-start+1);
        }
        
        return s.size()-Ans;
    }
};
