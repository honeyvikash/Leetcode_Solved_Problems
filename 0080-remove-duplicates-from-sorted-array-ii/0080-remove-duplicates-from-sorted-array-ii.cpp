class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        // ->it is the place where we will add elements
        int it = 0;
        for(auto &ele:a)
        {
            if(it == 0 || it == 1 || a[it-2]!=ele)
            {
                a[it]=ele;
                it++;
            }
        }
        return it;
    }
};