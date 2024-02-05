class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int s1=0,s2=0;
        int cmn=0,mn=0,cmx=0,mx=0;
        
        for(int i=0;i<n;i++)
        {
            s1 += nums1[i];
            s2 += nums2[i];
            
            int tmp = nums1[i]-nums2[i];
            
            cmx = max(cmx+tmp,tmp);
            mx  = max(cmx,mx);

            cmn = min(cmn+tmp,tmp);
            mn  = min(cmn,mn);
        }
        return max(s1-mn,s2+mx);
    }
}; 