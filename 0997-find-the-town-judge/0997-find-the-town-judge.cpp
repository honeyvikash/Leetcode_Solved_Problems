class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector< int > ton(n,0),tot(n,0);
        for(auto &val : trust)
            ton[val[1]-1] += 1,tot[val[0]-1] += 1;
        
        for(int i=0 ; i<n ; i++)
            if( ton[i]==n-1 && 0==tot[i] ) return i+1;
        return -1; 
    }
};