class Solution {
public:
    int consecutiveNumbersSum(int n) {
        long long cnt = 0;
        for (long long l = 1; l * (l + 1) < 2 * n; l++)
        {
            double a = (1.0 * n - (l * (l + 1)) / 2) / (l + 1);
            if (floor(a) == ceil(a))
                cnt++;
        }
        return cnt+1;
    }
};