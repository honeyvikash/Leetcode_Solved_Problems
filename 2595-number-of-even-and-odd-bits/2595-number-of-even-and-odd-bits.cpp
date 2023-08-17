class Solution {
public:
    vector<int> evenOddBit(int n) {
        int e=0,o=0;
        int ch = 0;
        while(n > 0)
        {
            if(n&1 && ch == 0 ) e++;
            else if(n&1 && ch == 1)o++;
            
            ch = !ch;
            n = n>>1;
        }
        return {e,o};
    }
};