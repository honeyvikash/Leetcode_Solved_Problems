class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int ans = 0;
        int n = piles.size();
        int ptr1 = n-2,ptr2 = 0;
        while(ptr1>ptr2)
        {
            ans+=piles[ptr1];
            ptr1-=2;
            ptr2++;
        }
        return ans;
    }
};