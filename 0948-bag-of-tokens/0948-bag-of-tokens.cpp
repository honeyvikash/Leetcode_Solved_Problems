class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int currScore = 0;
        int maxScore = 0;

        int s = 0, e = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());
        
        while (s <= e)
        {
            if (tokens[s] > power && currScore == 0)
                return maxScore;

            else if (tokens[s] <= power)
            {
                power -= tokens[s];
                currScore++;
                s++;
            }
            else if (currScore >= 1)
            {
                power += tokens[e];
                currScore--;
                e--;
            }
            maxScore = max(maxScore, currScore);
        }
        return maxScore;
    }
};