class Solution {
public:
    int numberOfChild(int n, int k) {
        int i=0 ;
        int kk=0 ;
        bool f = false ;
       while(true)
       {
           //cout<<kk<<" "<<i<<endl;
           kk++ ;
           
               if(i==0 || i==n-1) {
                   f=!f ;
               }
               
               if(f) i++ ;
               else i-- ;
           
           if(k==kk) break ;
       }
        return i ;
    }
};