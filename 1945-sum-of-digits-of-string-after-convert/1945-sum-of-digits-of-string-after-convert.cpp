class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                temp += to_string(s[i]-'a'+1);
            }
        }
        int sum =0;
        while(k--){
            sum =0;
            for(int i=0; i<temp.size(); i++){
                sum += temp[i]-'0';
            }
            temp = to_string(sum);
        }
        return sum;
    }
};