class Solution {
public:
    int majorityElement(vector<int>& a) {
        unordered_map<int,int>m;
        for(int i=0;i<a.size();i++)
        {
            m[a[i]]++;
        }
        int maxa=INT_MIN;
        int ans;
        for(auto &it:m)
        {
            if(it.second>maxa)
            {
                maxa=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};