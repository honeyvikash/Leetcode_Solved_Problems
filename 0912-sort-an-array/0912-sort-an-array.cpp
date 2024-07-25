class Solution {
public:
    void merge(vector<int>&answer, int start, int mid, int end)
    {
        vector<int> sorted;
        int i = start, j= mid+1;
        while(i<=mid&& j<=end)
        {
            if(answer[i]<answer[j])
            {
                sorted.push_back(answer[i]);
                i++;
            }
            else
            {
                sorted.push_back(answer[j]);
                j++;
            }
        }
        while(i <= mid)
        {
            sorted.push_back(answer[i++]);
        }
        while(j <= end)
        {
            sorted.push_back(answer[j++]);
        }
        j=0;
        for(i=start; i<=end; i++)
        {
            answer[i] = sorted[j++] ;
        }
    }
    void mergeSort(vector<int>& nums, int start,int end){
        if(start >= end)
        {
            return;
        }
        int mid = start + (end - start)/2 ;
        mergeSort(nums, start,mid);
        mergeSort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int start =0;
        int end = nums.size()-1;
        mergeSort(nums,start,end);
        return nums;
    }
};