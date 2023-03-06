class Solution {
public:
#define all(a) (a).begin(), (a).end()
    int findKthPositive(vector<int>& a, int k) {
        int ans=0;
        for(int i=1;i<10000000;i++)
        {
            if(!binary_search(all(a),i))
            {
                ans=i;
                k--;
            }
            if(k==0)break;
        }
        return ans;
    }
};