class Solution {
public:
    void flipArr(vector < int >& a, int idx) 
    {
        int i = 0, j = idx - 1;
        while ( i < j ) swap(a[i++], a[j--]);
        return;
    }
    vector<int> pancakeSort(vector<int>& a) {
        vector < int > ans;
        int n = a.size();
        while ( a.size() ) 
        {
            n = a.size();
            int maxIdx = max_element(a.begin(), a.end()) - a.begin();

            flipArr(a, maxIdx + 1);
            
            ans.push_back(maxIdx + 1);

            flipArr(a, n);

            ans.push_back(n);

            a.pop_back();
        }
        return ans;
    }
};