    /*iss question me bhot saare checkpoints hai
      1.if string null return 0
      2.remove widespaces
      3.if after removing widespaces then return 0
      4.check for sign
      5.check for no. is within range 
      6.if no. is out of range and sign is + then return intmax else return intmin
      7.return sign*no.
    */
class Solution 
{
public:
    int atoi(string &s,int sign,int i,long ans)
    {
        if(sign*ans>=INT_MAX)
        {
            return INT_MAX;
        }
        if(sign*ans<=INT_MIN)
        {
            return INT_MIN;
        }
        if(i>=s.size() || s[i]<'0' || s[i]>'9')
        {
            return sign*ans;
        }
        ans = atoi(s,sign,i+1,(ans*10+(s[i]-'0')));
        return ans;
    }
    int myAtoi(string s) 
    {
        int i=0,n = s.size(),sign = 1;
        while(i<n && s[i] == ' ')
        {
            ++i;
        }
        if(s[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else if(s[i] == '+')
        {
            ++i;
        }
        return atoi(s,sign,i,0);
    }
};