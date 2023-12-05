class Solution {
public:
    int numberOfMatches(int n) {
        int mat=0;
        int team=0;
        int sum=0;
        while(n!=1)
        {
            if(n%2==0)
            {
                mat=n/2;
                team=n/2;
                sum+=mat;
                n=team;
            }
            else
            {
                mat=((n-1)/2);
                team=((n-1)/2)+1;
                sum+=mat;
                n=team;
            }
        }
        return sum;
    }
};