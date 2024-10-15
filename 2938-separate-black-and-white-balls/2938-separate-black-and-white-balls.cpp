class Solution {
#define lli long long int 
public:
    long long minimumSteps(string s) {
        int black=0; 
        lli step=0; 
        for (char&c:s) if (c=='1') black++; 

        if (black==0) return 0; 

        int i=s.length()-1, j = s.length()-1; 
        while (1){
            if (s[i]=='1') break;
            i--;
        }

        while(black){
            if (s[i]=='1'){
                step += (lli) j-i; 
                j--; 
                i--; 
                black--;
            }
            else{
                i--;
            }
        }
        return step ;
    }
};