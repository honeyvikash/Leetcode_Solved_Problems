class Solution {
public:
    int totalMoney(int n) {
        int quo=n/7;
        int ans=0;
        for(int i=1;i<=quo;i++)
        {
            ans+=7*(i+3);
        }
        for(int i=7*quo;i<n;i++)
        {
            ans+=++quo;
        }
        return ans;
    }
};