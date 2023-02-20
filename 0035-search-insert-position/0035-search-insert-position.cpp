class Solution {
public:
    int searchInsert(vector<int>& a, int t) {
         int start=0;
        int end=a.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(a[mid]==t)
            {
                return mid;
            }
            else if(a[mid]>t)
            {
                end=mid-1;
            }
            else 
            {
                start=mid+1;
            }
        }
        return start;
    }
};