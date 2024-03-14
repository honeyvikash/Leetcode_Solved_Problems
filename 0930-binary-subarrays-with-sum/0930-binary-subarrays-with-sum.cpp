class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int goal) 
    {
        int i=0,j=0,count=0,sum=0;
        while(j<a.size( ))
        {
            sum+=a[j];
            while(i<j && sum>goal)
            {
                sum-=a[i];
                i++;
            }
            if(sum==goal)
            {
                int l=i;
                while(l<j && a[l]==0)
                {
                    count++;
                    l++;
                }
                count++;
            }
            j++;
        }
        return count;
    }
};