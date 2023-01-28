class Solution {
public:
    string interval(int first, int last) 
    {
        return first == last ? to_string(first) : to_string(first) + "->" + to_string(last);
    }
    
    vector<string> summaryRanges(vector<int>& a) {
        vector<string> ans;
        if (a.size() == 0)return ans;
            
        int first = a[0];
        for (int i=1; i<a.size(); ++i) 
        {
            if (a[i-1]+1 != a[i]) 
            {
                ans.push_back(interval(first, a[i-1]));
                first = a[i];
            }
        }
        ans.push_back(interval(first, a.back()));
        return ans;
    }
};