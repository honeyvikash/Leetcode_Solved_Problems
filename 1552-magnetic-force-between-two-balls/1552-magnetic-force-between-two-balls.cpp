class Solution {
public:
    bool isValid(vector<int> &position, int val, int m){
        int initial=position[0],n=position.size();
        m--;
        for(int i=1;i<n;i++)
        {
            if(position[i]-initial>=val)
            {
                m--;
                initial=position[i];
            }
            if(m==0)
                return true;                
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size(),l=0,r=1e9,ans,mid;
        sort(position.begin(),position.end());
        r = position[n-1] - position[0];
        while(l<=r)
        {
            mid=(l+r)/2;
            if(isValid(position,mid,m))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;        
    }
};
