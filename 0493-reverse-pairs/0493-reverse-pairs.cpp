class Solution {
public:
    int merge(vector<int>&arr,vector<int>&temp,int l,int m,int r)
    {
        int i=l,j=m,k=l,inv=0;
        while(i<=m-1)
        {
            while(j<=r and arr[i]>(long)2*arr[j])j++;
            inv+=j-m;
            i++;
        }
        i=l,j=m,k=l;    
        while(i<=m-1 and j<=r)
        {
            if(arr[i]<=arr[j])temp[k++]=arr[i++];
            else temp[k++]=arr[j++];
        }
        while(i<=m-1)temp[k++]=arr[i++];
        while(j<=r)temp[k++]=arr[j++];
        for(int i=l;i<=r;i++)arr[i]=temp[i];
        return inv;
    }
    int mergeSort(vector<int>&nums,vector<int>&temp,int l,int r){
        int inv=0;
        if(r>l)
        {
            int m=l+(r-l)/2;
            inv+=mergeSort(nums,temp,l,m);
            inv+=mergeSort(nums,temp,m+1,r);
            inv+=merge(nums,temp,l,m+1,r);
        }
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        vector<int>temp(nums.size());
        return mergeSort(nums,temp,0,nums.size()-1);
    }
};