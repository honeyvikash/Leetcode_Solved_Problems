class Solution {
public:
    long long dividePlayers(vector<int>& a) {
        sort(a.begin(),a.end());
        if(a.size()==2)return a[0]*a[1];
        long long ans=-1,sum=a[0]+a[a.size()-1];
        int i=0,j=a.size()-1;
        long long pro=0;
        while(i<j)
        {
             long long temp_ans=a[i]+a[j];
            if(temp_ans!=sum)
            {
                return -1;
            }
            pro+=(a[i]*a[j]);
            ans=max(ans,pro);
            i++;
            j--;
        }
        return ans;
    }
};