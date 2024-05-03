class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int idx = 0;
        for(auto &ele:a)
        {
            if(idx == 0 || idx == 1 || a[idx-2]!=ele)
            {
                a[idx]=ele;
                idx++;
            }
        }
        return idx;
    }
};