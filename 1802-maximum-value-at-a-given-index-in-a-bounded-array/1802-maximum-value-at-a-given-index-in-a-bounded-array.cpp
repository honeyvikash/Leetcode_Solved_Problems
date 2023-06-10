class Solution {
public:
    bool isPos(int n,int index,int maxSum,int mid){
        long long totalSum = mid;
        int left = index;
        int right = (n-index)-1;
        
        long long t = mid-1;
        totalSum += t*(t+1);
        if( left>=(mid-1) ){
            totalSum += left-(mid-1);
        }else{
            t = (mid-1)-left;
            totalSum -= t*(t+1)/2;
        }
        if( right>=(mid-1) ){
            totalSum += right-(mid-1);
        }else{
            t = (mid-1)-right;
            totalSum -= t*(t+1)/2;
        }
        return totalSum<=maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        int s = 1,e = maxSum;
        int ans;
        while( s<=e ){
            int mid = s+(e-s)/2;
            if( isPos(n,index,maxSum,mid) ){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
};