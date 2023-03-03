class Solution {
public:
    string oddString(vector<string>& words) {
        vector<string>v;
        for(auto i:words)
        {
            string a="";
            for(int j=0; j<i.size()-1;j++)
            {
                a += (i[j+1] - i[j]);
            }
            v.push_back(a);
        }
        for(int i=0; i<v.size(); i++)
        {
            if(count(v.begin(), v.end(), v[i]) == 1)
                return words[i];
        }
        return "";
    }
};