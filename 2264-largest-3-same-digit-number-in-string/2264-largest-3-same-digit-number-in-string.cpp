class Solution {
public:
    string largestGoodInteger(string s) {
            string a[10] = {"999", "888", "777", "666", "555", "444", "333",                                "222", "111", "000"};
        for (int i = 0; i < 10; i++)
        {
            size_t found = s.find(a[i]);
            if (found !=string::npos)
            {
                return a[i];
            }
        }
        return "";
    }
};