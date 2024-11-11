class Solution
{
public:
    vector<int> prime(int n)
    {
        vector<bool> primes(n + 1, true);
        vector<int> pre;
        primes[0] = primes[1] = false;

        for (int i = 2; i * i <= n; i++)
        {
            if (primes[i])
            {

                for (int j = i * i; j <= n; j += i)
                    primes[j] = false;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (primes[i])
            {
                pre.push_back(i);
            }
        }
        return pre;
    }
    bool primeSubOperation(vector<int> &nums)
    {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<int> pre = prime(m);
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                continue;
            }
            else
            {
                int x = nums[i] - nums[i + 1];
                auto it = upper_bound(pre.begin(), pre.end(), x);
                if (it == pre.end())
                {
                    return false;
                }
                if (pre[it - pre.begin()] >= nums[i])
                {
                    return false;
                }
                nums[i] -= pre[it - pre.begin()];
            }
        }
        return true;
    }
};