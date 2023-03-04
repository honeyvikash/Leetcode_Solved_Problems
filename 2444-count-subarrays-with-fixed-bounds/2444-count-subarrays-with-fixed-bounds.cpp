class Solution {
public:
    long long countSubarrays(vector<int>& a, int minK, int maxK) {
        long long ans=0;
        long long start=0,minstart=0,maxstart=0;
        bool min_check=false,max_check=false;
        for(int i=0;i<a.size();i++)
        {
            long long x = a[i];
            if(x<minK || x>maxK)
            {
                min_check=false;
                max_check=false;
                start=i+1;
            }
            if(x==minK)
            {
                min_check=true;
                minstart=i;
            }
            if(x==maxK)
            {
                max_check=true;
                maxstart=i;
            }
            if(min_check && max_check)
            {
                ans+=min(minstart,maxstart)-start+1;
            }
        }
        return ans;
    }
};