class Solution {
public:
    string shiftingLetters(string s, vector<int>& nums) {
        int n = nums.size();
        
        vector<long long int>suffix_sum(n,0);
        
        suffix_sum[n-1] = nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {   
            suffix_sum[i] = suffix_sum[i+1] + nums[i] ;
        }
        
        // cout<<"i am here";
        
        for(int i=0;i<n;i++)
        {
            suffix_sum[i] = (suffix_sum[i]%26) ;
        }
        
        
        for(int i=0;i<n;i++)
        {
            s[i] = (s[i]-'a' + suffix_sum[i])%26+ 'a';
        }
        return s;
    }
};