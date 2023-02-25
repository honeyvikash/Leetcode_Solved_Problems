class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxi(prices.size());
        int n = prices.size();
        int ma = INT_MIN;
        for(int i =n-1;i>=0;i--){
            ma = max(ma,prices[i]);
            maxi[i] = ma;
        }
        int ans = 0;
        for(int i =0;i<n;i++){
            ans = max(maxi[i]-prices[i],ans);
        }
        return ans;
    }
};