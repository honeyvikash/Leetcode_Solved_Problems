class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<unordered_map<int,int>> mp;
        vector<string> v;
        int i = -1;

        for(auto& a:words)
        {
            i++;
            mp.push_back(unordered_map<int,int>());
            for(auto& b:a)
                mp[i][b]++;
        }

        int j =0 ,mn = -1;
        for(auto&a :words[0])
        {
            for(i = 0 ; i < words.size() ; ++i)
            {
                //mn = min()
                if(mp[i][a] < 1)
                    j = 1;
            }
            if(j!=1)
            {
                v.push_back(string(1, a));
                for(i = 0 ; i < words.size() ; ++i)
                    mp[i][a]--;
                j=0;
            } 
            j=0;
        }
        return v;
    }
};