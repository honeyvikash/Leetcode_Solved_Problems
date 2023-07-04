class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        long long i = 0,j = 1;
        multiset<long long> st;
        st.insert(nums[0]);
        long long maxi = nums[0],mini = nums[0];
        while(j<n)
        {
            while(i<j && (abs(nums[j]-maxi)>2 || abs(nums[j]-mini)>2))
            {
                auto it = st.find(nums[i]);
                st.erase(it);
                ans+=(j-i);
                // cout<<j<<" "<<i<<'\n';
                if(st.size()>0)
                {
                    mini = *st.begin();
                    it = st.end();
                    it--;
                    maxi = *it;   
                }
                i++;
            }
            st.insert(nums[j]);
            auto it1 = st.end();
            it1--;
            maxi = *it1;
            mini = *st.begin();
            j++;    
        }
        if(st.size()>0)
        {
            // cout<<st.size()<<" ";
            long long len = (long long)st.size();
            ans+=(len*(len+1))/2;
        }
        return ans;
    }
};