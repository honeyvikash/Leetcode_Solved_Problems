class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> st ;
        for(auto it : nums) st.insert(it) ;
        int maxi = -1 ;

        for(auto it : nums)
        {
            if(it<0) continue ;

            int find = -it ; 
            if(st.find(find)!=st.end()) maxi = max(maxi , it) ;
        }
        return maxi ;
    }
};