class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        vector<int>v;
         unordered_map<int,int>m;
         int n=a.size();
        for(int i=0;i<n;i++)
        {
            m[a[i]]++;
        }
        for(auto &it:m)
        {
            if(it.second>(n/3))
            {
                v.push_back(it.first);
            }
        }
        return v;
    }
};