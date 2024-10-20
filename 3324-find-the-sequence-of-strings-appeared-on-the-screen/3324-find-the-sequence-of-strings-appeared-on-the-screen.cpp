class Solution {
public:
    vector<string> stringSequence(string target) {
        string curr ;
        vector<string> ans;
        for(int i=0;i<target.size();i++){
            curr+= 'a';
            ans.push_back(curr);
            for(int j = 1;j<26;j++){
                if(curr.back()== target[i]) break;
                curr.back() = curr.back()+1;
                ans.push_back(curr);
            }
            
        }
        return ans;
    }
};