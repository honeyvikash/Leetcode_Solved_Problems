class Solution {
public:
    /*iss question me bhot saare checkpoints hai
    //A.AND Ques of the day
      1.if string null return 0
      2.remove widespaces
      3.if after removing widespaces then return 0
      4.check for sign
      5.check for no. is within range 
      6.if no. is out of range and sign is + then return intmax else return intmin
      7.return sign*no.
    */
    int myAtoi(string s) {
        int n = s.size();
        if(n==0)return 0;
        
        int i=0;
        for(i=0;i<n && s[i]==' ';i++);
            
        if(i==n)return 0;
        int sign = 1; // initially its +ve suppose
        if(s[i]=='-')
        {
            sign = -1;
            i++;
        }
        else if(s[i]=='+')i++;
        
        long long no=0;
        while(i<n && no<INT_MAX && isdigit(s[i]))
        {
            no = no*10 + (s[i]-'0');
            i++;
        }
        
        if(no>INT_MAX)
        {
            if(sign==1)return INT_MAX;
            return INT_MIN;
        } 
        return sign*no;
    }
};