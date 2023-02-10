class Solution {
public:
    vector<int> numberOfPairs(vector<int>& a) {
        unordered_map<int,int>m;
        int akela=0;
        int pair=0;
        for(int i=0;i<a.size();i++)
        {
            m[a[i]]++;
        }
        for(auto &x:m)
        {
            if(x.second>=2)
            {
                pair+=(x.second/2);
                akela+=(x.second%2);
            }
            else if(x.second=1)
            {
                akela++;
            }
        }
        return {pair,akela};
    }
};