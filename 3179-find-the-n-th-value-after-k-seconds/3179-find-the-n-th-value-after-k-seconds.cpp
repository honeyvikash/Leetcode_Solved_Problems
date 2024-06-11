class Solution {
public:
    int modo = 1e9+7 ;
    int valueAfterKSeconds(int n, int k) {
        vector<long long>arr(n,1) ;
        
        while(k--)
        {
            for(int i=1 ; i<n ; i++)
            {
                arr[i]=(arr[i-1]+arr[i])%modo ;
            }
        }
        
        int ans = arr[n-1]%modo ;
        return ans ;
    }
};