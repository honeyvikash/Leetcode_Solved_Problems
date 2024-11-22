class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> m;
        unordered_map<string,string> flip;
        for(auto row:matrix){
            string s,fp;
            for(int i=0;i<row.size();i++){
                s+=row[i]+'0';
                fp+=(row[i]^1)+'0';
            }
            m[s]++;
            flip[s]=fp;
        }
        int ans=0;
        for(auto x:m){
            if(m.find(flip[x.first])!=m.end())
                ans=max(ans,x.second+m[flip[x.first]]);
            else
                ans=max(ans,x.second);
        }
        return ans;
    }
};