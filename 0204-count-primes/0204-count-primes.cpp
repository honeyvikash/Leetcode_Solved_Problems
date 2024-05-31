class Solution {
public:
    int countPrimes(int n) {
         if(n<3)
        {
            return 0;
        }
        
        int cnt=0;
        bool a[n];
        for(int i=2;i<n;i++)
        {
            a[i]=true;
        }
        for(int i=2;i<sqrt(n);i++)
        {
            if(a[i]==true)
            {
                for(int j=i*i;j<n;j=j+i)
                {
                    a[j]=false;
                }
            }
        }
        for( int i=2;i<n;i++)
        {
        
           if(a[i]==true)cnt++; 
        }
        return cnt;
    }
};