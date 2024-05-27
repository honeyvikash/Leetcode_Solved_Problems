class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m1;
        for(int i=0;i<s.size();i++)
        {
            m1[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto x :m1)
        {
            v.push_back(make_pair(x.second,x.first));
        }
        sort(v.begin(),v.end(),greater<>());
        string ans;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first==1)
            {
                ans+=v[i].second;
            }
            else
            {
                v[i].first--;
                ans+=v[i].second;
                i--;
            }
        }
        return ans;
    }
};