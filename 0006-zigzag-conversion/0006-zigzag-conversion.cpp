class Solution {
public:
    string convert(string s, int numRows) {
         if( numRows==1 )  return s;
        vector<string> rows(numRows);
        int currRow = 0;
        int add = 1;
        for(auto val : s)
        {
            rows[currRow].push_back(val);
            currRow += add;
            if( numRows==currRow )
            {
                currRow = numRows-2;
                add = -1;
            }
            else if( currRow==-1 )
            {
                add = 1;
                currRow = 1;
            }
        }
        string ans;
        for(auto val : rows)
        {
            ans.append(val);
        }
        return ans;
    }
};