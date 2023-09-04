class Solution {
public:
    string findDifferentBinaryString(vector<string>& a) {
        string ans = "";
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i][i]=='0')
                ans+='1';
            else
                ans+='0';
        }
        return ans;
    }
};