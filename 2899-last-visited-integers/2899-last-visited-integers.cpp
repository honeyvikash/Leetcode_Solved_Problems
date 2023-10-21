class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> tmp;
        int cnt = 0;
        vector<int> ans;
        for(int i=0;i<words.size();i++)
        {
            if(words[i]!="prev")
            {
                tmp.push_back(stoi(words[i]));
                cnt = 0;
            }
            else
            {
                cnt++;
                vector<int> tmp1;
                for(auto &j:tmp)
                    tmp1.push_back(j);
                if(tmp1.size()<cnt)
                {
                    ans.push_back(-1);
                    continue;
                }
                reverse(tmp1.begin(),tmp1.end());
                ans.push_back(tmp1[cnt-1]);
            }
        }
        return ans;
    }
};