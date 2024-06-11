class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        int n = p.size() ;
        
        int cnt = 0 ;
        sort(p.begin(),p.end()) ;
        vector<int>cur = p[0] ;
        for(int i=1 ; i<p.size() ; i++)
        {
            if(p[i][0]<=cur[1])
            {
                cur[0]=max(cur[0],p[i][0]) ;
                cur[1]=min(cur[1],p[i][1]) ;
            }
            else
            {
                cnt++ ;
                cur = p[i] ;
            }
        }

        cnt++ ;
        return cnt ;
    }
};