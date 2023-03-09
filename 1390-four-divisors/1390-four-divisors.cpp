/*IMPORTANT*/
/*Exactly four factors
Some examples of numbers with exactly four factors are 6, 15, and 21.  For 6, the factors are 1, 2, 3, and 6, and for 15, the factors are 1, 3, 5, and 15. Similarly, for 21, the factors are 1, 3, 7, and 21. Students soon see that numbers of the form p x q, where p and q are distinct primes (p ≠ q) will have only four factors: 1, p, q, and pq. However, these aren’t the only numbers that have exactly four factors. For example, 8 has 1, 2, 4, and 8 as factors, and 8 = 23. Any number that is of the form p3 for some prime p also has exactly four factors: 1, p, p2 and p3.*/

class Solution {
public:
    int have_four_factors(int x)
    {
        int cnt=0;
        int sum=0;
        for(int i=1;i*i<=x;i++)
        {
            if(x%i==0)
            {
                sum+=i;
                cnt++;
                if(x/i!=i)
                {
                    sum+=(x/i);
                    cnt++;
                }
            }
        }
        if(cnt==4)return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& a) {
        int sum=0;
        for(int i=0;i<a.size();i++)
        {
            sum+=have_four_factors(a[i]);
        }
        return sum;
    }
};