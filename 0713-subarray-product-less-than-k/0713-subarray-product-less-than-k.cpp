class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int n = a.size();
        // int cnt = 0;
        // for(int i=0;i<n;i++)
        // {
        //     long long tmp = 1LL;
        //     int j = i;
        //     while(j<n)
        //     {
        //         tmp *= a[j];
        //         if(tmp<k)cnt++;
        //         j++;
        //         if(tmp>=k)break;
        //     }
        // }
        // return cnt;
        
        // unordered_map<long long,int>m;
        long long pro=1;
        long long count=0;
        int j=0;
        for(long long i=0;i<n;i++)
        {
             pro*=a[i];
             while(pro>=k && j<n)
             {
                 pro/=a[j];
                 j++;
             }
             if(pro<k)
             {
                 count+=(i-j+1);
             }
        }
        return count;
    }
};