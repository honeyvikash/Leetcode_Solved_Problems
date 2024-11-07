class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<int> arr(32, 0);
        for(int i=0; i<n; i++)
        {
            int ind = 0;
            int num = candidates[i];
            while(num)
            {
                if(num&1)
                {
                    arr[ind] += 1; 
                }
                ind++;
                num >>= 1;
            }
        }
        int len = 1;
        for(int i=0; i<32; i++)
        {
            len = max(len, arr[i]);
        }
        return len;
    }
};