class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& w) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s(w.begin(),w.end());
        s.erase(beginWord);
        while(!q.empty())
        {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == endWord) return step;
            for(int i=0;i<word.size();i++)
            {
                char ori = word[i];
                for(char ch ='a';ch<='z';ch++)
                {
                    word[i]= ch;
                    if(s.find(word)!=s.end())
                    {
                        s.erase(word);
                        q.push({word,step+1});
                    }
                    
                }
                word[i]=ori;
            }
        }
        return 0;
    }
};