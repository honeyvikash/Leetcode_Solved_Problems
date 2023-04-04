class Solution {
public:
    int partitionString(string s) {
        int par=0,num=0;
        for(auto &x:s)
        {
            if(num&(1<<(x-'a')))
            {
                par++;
                num=0;
                
            }
            num |= (1<<(x-'a'));
        }
        return par+1;
    }
};