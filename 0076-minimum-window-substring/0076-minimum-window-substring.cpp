class Solution {
public:
    bool isValid(unordered_map<char,int>& sMap,unordered_map<char,int>& tMap)
    {
        if(sMap.size()<tMap.size())
        return false;
        for(auto &i:tMap)
        {
            if(sMap.find(i.first)==sMap.end())
            return false;
            if(sMap[i.first]<i.second)
            return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char,int> tMap,sMap;
        for(auto &i:t)
        tMap[i]++;

        int i = 0,j = 0;
        int siz = INT_MAX;
        string ans = "";
        int p1 = -1,p2 = -1;

        while(j<n)
        {
            sMap[s[j]]++;
            if(isValid(sMap,tMap))
            {
                while(isValid(sMap,tMap) && i<=j)
                {
                    if(siz>j-i+1)
                    {
                        siz = j-i+1;
                        p1 = i;
                        p2 = j;
                    }
                    sMap[s[i]]--;
                    if(sMap[s[i]]==0)
                    sMap.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        if(p1==-1 || p2==-1)
        return "";
        while(p1<=p2)
        {
            ans+=s[p1++];
        }
        return ans;
    }
};