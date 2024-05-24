class Solution {
public:
    int solve(vector<string>& words, vector<char>& letters, vector<int>& score, int idx,
              unordered_map<char, int>& mp) 
    {
        if (idx == words.size()) 
        {
            return 0;
        }
        
        int pick = 0;
        bool canPick = true;
        
        unordered_map<char, int> tempMp = mp;
        
        for (char c : words[idx]) 
        {
            if (tempMp[c] > 0) 
            {
                tempMp[c]--;
                pick += score[c - 'a'];
            } 
            else 
            {
                canPick = false;
                break;
            }
        }
        int pickScore = 0;
        if (canPick) 
        {
            pickScore = pick + solve(words, letters, score, idx + 1, tempMp);
        }

        int notPickScore = solve(words, letters, score, idx + 1, mp);

        return max(pickScore, notPickScore);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> mp;
        for (auto c : letters) mp[c]++;
        return solve(words, letters, score, 0, mp);
    }
};