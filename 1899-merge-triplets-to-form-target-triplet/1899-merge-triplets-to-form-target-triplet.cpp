class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triples, vector<int>& target) {
        int cnt = 0;
        int a = target[0];
        int b = target[1];
        int c = target[2];
        int n = triples.size();
        int f1 = 0,f2 = 0,f3 = 0;
        
        for(int i=0;i<n;i++)
        {
            if(triples[i][0]<=a && triples[i][1]<=b && triples[i][2]<=c)
            {
                cnt++;
                if(triples[i][0]==a)
                f1 = true;
                if(triples[i][1]==b)
                f2 = true;
                if(triples[i][2]==c)
                f3 = true;
            }
            if(triples[i][0]==a && triples[i][1]==b && triples[i][2]==c)
            return true;
        }
        
        if(cnt>=2 && f1 && f2 && f3)return true;
        
        return false;
    }
};