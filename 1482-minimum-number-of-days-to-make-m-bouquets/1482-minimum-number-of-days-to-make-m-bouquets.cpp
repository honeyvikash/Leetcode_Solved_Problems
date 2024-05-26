class Solution {
public:
    
    bool possible(vector<int>& a, int day,int m, int k)
    {
        int n=a.size();
        int cnt=0,nod=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=day){
                cnt++;
            }
            else{
                nod+=(cnt/k);
                cnt=0;
            }
        }
        nod+=(cnt/k);
        return nod>=m;
    }

    int minDays(vector<int>& a, int m, int k) {
        long long val=m*1ll*k*1ll;
        int n=a.size();
        if(val>n) return -1;

        int min1=INT_MAX,max1=INT_MIN;
        for(int i=0;i<n;i++)
        {
            min1=min(min1,a[i]);
            max1=max(max1,a[i]);
        }

        int low=min1,high=max1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(a,mid,m,k))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};