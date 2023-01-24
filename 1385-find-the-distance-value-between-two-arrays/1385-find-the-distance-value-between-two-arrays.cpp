class Solution {
public:
    int findTheDistanceValue(vector<int>& a1, vector<int>& a2, int d) {
        sort(a2.begin(),a2.end());
        int ans=0;
        for(auto &x:a1)
        {
            //start binSearch
            int s=0,e=a2.size()-1;
            bool check=true;
            while(s<=e)
            {
                int mid=s+(e-s)/2;
                if(abs(a2[mid]-x)<=d)
                {
                   check=false;
                    break; 
                }
                 else if(a2[mid]<x) s=mid+1;
                 else e=mid-1;
            }
            if(check)ans++;
        }
        return ans;
    }
};