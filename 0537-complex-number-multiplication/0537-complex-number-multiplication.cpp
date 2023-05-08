class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        
        int i = find(num1.begin(),num2.end(),'+')-num1.begin();
        int j = find(num2.begin(),num2.end(),'+')-num2.begin();
        
        string r1 = num1.substr(0, i);
        string r2 = num2.substr(0, j);
        
        //cout<<a1<<' '<<a2<<endl;
        
        string i1 = num1.substr(i+1, num1.size()-i-2);
        string i2 = num2.substr(j+1, num2.size()-j-2);
        
        //cout<<b1<<' '<<b2<<endl;
        
        string ans;
        ans += to_string(stoi(r1)*stoi(r2)-stoi(i1)*stoi(i2));
        ans += "+";
        ans += to_string(stoi(r1)*stoi(i2)+stoi(r2)*stoi(i1));
        ans += "i";
        
        return ans;
        
    }
};