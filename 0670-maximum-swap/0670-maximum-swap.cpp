class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int ma = num;
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                char t = s[j];
                s[j]=s[i];
                s[i]=t;
                ma = max(ma,stoi(s));
                s[i]=s[j];
                s[j]=t;
            }
        }
        return ma;
    }
};