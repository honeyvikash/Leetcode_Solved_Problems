class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<vector<int>> vect(26,vector<int>(26,0));
        unordered_set< string > ust(ideas.begin(),ideas.end());
        for(auto &val : ideas)
        {
            char prev = val[0];
            for(char ch='a' ; ch<='z' ; ch++)
            {
                val[0] = ch;
                if( ust.find(val)==ust.end() )
                {
                    vect[prev-'a'][ch-'a'] += 1;
                }
            }
        }
        long long ans = 0; 
        for(int i=0 ; i<26 ; i++)
        {
            for(int j=0 ; j<26 ; j++)
            {
                ans += (long long)vect[i][j]*vect[j][i];
            }
        }
        return ans;
    }
};