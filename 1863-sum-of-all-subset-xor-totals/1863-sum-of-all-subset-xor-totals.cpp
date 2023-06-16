class Solution {
public:
    int subsetXORSum(vector<int>& a) {
        int sum = 0;
        int n = a.size();
       
        for (int i = 0; i < (1 << n); i++) 
        {
            int x = 0;
            for (int j = 0; j < n; j++) 
            {
                if (i & (1 << j)) 
                {
                    x ^= a[j];
                }
            }
            sum += x;
        }
        
        return sum;
    }
};