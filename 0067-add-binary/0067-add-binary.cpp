class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;

        string ans="";
        int carry=0,a_aval,b_aval;

        while(i>=0 || j>=0 || carry>0)
        {
            a_aval=0;
            b_aval=0;
            if(i>=0)
            {
                a_aval=a[i]-'0';
            }
            if(j>=0)
            {
                b_aval=b[j]-'0';
            }

            int sum=a_aval+b_aval+carry;
            char c=sum%2+'0';
            ans=c+ans;
            carry=0;
            if(sum>1)
            {
                carry=1;
            }
            i--;
            j--;
        }
        return ans;
    }
};