class Solution {
public:
    int minSwaps(string s) {
        int c=0;
        for(auto &x:s)
        {
            if(x=='[')c++;
            else c=max(0,c-1);
        }
        return (c+1)/2;
    }
};