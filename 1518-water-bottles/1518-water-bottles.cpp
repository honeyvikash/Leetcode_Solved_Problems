class Solution {
public:
    int numWaterBottles(int nb, int nx) {
        int n = nb;
        while(nb>=nx)
        {
            n = n+nb/nx;
            nb = nb/nx  + nb%nx;
            // cout<<n<<" "<<nb<<" "<<nx<<endl;
        }
        return n;
    }
};