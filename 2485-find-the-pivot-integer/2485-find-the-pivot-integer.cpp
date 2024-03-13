class Solution {
public:
    int pivotInteger(int n) {
        double k=n*(n+1)/2;
        if(sqrt(k)==floor(sqrt(k)) && sqrt(k)==ceil(sqrt(k)))
        {
            return (int)((sqrt(k)));
        }
        return -1;
    }
};