/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int peakInd = -1;
        int len = arr.length();
        int l = 0,r = len-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int b = arr.get(mid);
            if(mid-1>=0 && mid+1<len)
            {
                int a = arr.get(mid-1);
                int c = arr.get(mid+1);
                if(a<b && b>c)
                {
                    peakInd = mid;
                    break;
                }
                else if(a<b && b<c)
                l = mid+1;
                else
                r = mid-1;
            }
            else if(mid-1>=0)
            {
                int a = arr.get(mid-1);
                if(b>a)
                {
                    peakInd = mid;
                    break;
                }
                else
                r = mid-1;
            }
            else if(mid+1<len)
            {
                int a = arr.get(mid+1);
                if(b>a)
                {
                    peakInd = mid;
                    break;
                }
                else
                l = mid+1;
            }
            
        }
        
        l = 0,r = peakInd;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            int ele = arr.get(mid);
            if(ele==target)
            return mid;
            else if(ele>target)
            r = mid-1;
            else
            l = mid+1;
        }
        
        l = peakInd, r = len-1;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            int ele = arr.get(mid);
            if(ele==target)
            return mid;
            else if(ele>target)
            l = mid+1;
            else
            r = mid-1;
        }
        return -1;
    }
};