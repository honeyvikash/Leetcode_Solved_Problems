class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi = 0 ;
        int n = nums.size() ;
        int check = 0 ; 

        int start = 0 ; 
        for(int end = 0 ; end<n ; end++)
        {
            while((check & nums[end])!=0)
            {
                check = check ^ nums[start];
                start++;
            }
            
            check = check | nums[end];
            int len = end - start +1 ; 
            maxi = max(maxi , len);
        }

        return maxi ;
    }
};