class Solution {
public:
    vector<int> intersect(vector<int>& a1, vector<int>& a2) {
        unordered_map<int,int>m1,m2;
        for(int i=0;i<size(a1);i++)m1[a1[i]]++;
        for(int i=0;i<size(a2);i++)m2[a2[i]]++;
        vector<int>ans;
        set<int>s(begin(a1),end(a1));
        for(auto &i:s)
        {
            int k=min(m1[i],m2[i]);
            if(k!=0)
            {
                while(k--)
                {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};