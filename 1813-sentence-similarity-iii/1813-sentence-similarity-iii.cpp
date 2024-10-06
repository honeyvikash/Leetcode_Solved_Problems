class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if (s1.size() < s2.size()) {
            string temp = s1;
            s1 = s2;
            s2 = temp;
        }
        
        vector<string> ar1;
        stringstream ss1(s1);
        string word;
        
        while (ss1 >> word) {
            ar1.push_back(word);
        }
        
        vector<string> ar2;
        stringstream ss2(s2);
        
        while (ss2 >> word){
            ar2.push_back(word);
        }
        
        int i1 = 0, i2 = 0, j1 = ar1.size() - 1, j2 = ar2.size() - 1;
        
        while (i2 <= j2){
            if(ar1[i1] == ar2[i2]){
                i1++;
                i2++;
            } 
            else if(ar1[j1] == ar2[j2]){
                j1--;
                j2--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};