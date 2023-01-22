class Solution {
public:
    long long minOperations(vector<int>& a1, vector<int>& a2, int k) {
        long long cnt=0;
        long long sum=0;
        long long n =a1.size();
        for(int i=0;i<n;i++)
        {
            if(a1[i]!=a2[i])
            {
                int diff = a1[i]-a2[i];
                if(k==0 || abs(diff)%k!=0)return -1;
                    
                cnt+=abs(diff)/k;
                sum+=diff;
            }
        }
        return sum==0 ? (cnt+1)/2 : -1;        
    }
};