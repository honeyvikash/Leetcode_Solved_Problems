class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        if(num[n-1]=='1' || num[n-1]=='3' || num[n-1]=='5' || num[n-1]=='7' || 
           num[n-1]=='9')
        {
            return num;
        }
        int k=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(num[i]=='1' || num[i]=='3'
                   || num[i]=='5' 
                   || num[i]=='7' || num[i]=='9')
            {
                    k=i;
                    string ans(num.begin(),num.begin()+i+1);
                    return ans;
            }
        }
        return "";
    }
};