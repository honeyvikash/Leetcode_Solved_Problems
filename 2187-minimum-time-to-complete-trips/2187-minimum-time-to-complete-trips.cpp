class Solution {
public:
    bool isPos(vector<int> &time,int target,long long limit)
    {
        long long ans = 0;
        for(auto val : time)
        {
            ans += limit/val;
        }
        return ans>=target;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int mx = 0;
        for(auto val : time)    mx = max(mx,val);
        long long s = 1,e = (long long)mx*totalTrips;
        long long ans;
        while(s<=e)
        {
            long long mid = s+(e-s)/2;
            if( isPos(time,totalTrips,mid) )
            {
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};