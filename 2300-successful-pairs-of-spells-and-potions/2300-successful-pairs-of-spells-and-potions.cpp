class Solution {
public:
    #define all(a) (a).begin(), (a).end()
    #define ll long long
    int binar(int num,vector<int> &p,long long success)
    {
        int len = p.size();
        int s=0,e=len-1;
        int ans = 0;
        while( s<=e )
        {
            int mid = s+(e-s)/2;
            if( ((ll)p[mid])*num>=success )
            {
                ans = len-mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        sort(all(p));
        vector<int> ans;
        for(int i=0; i<s.size() ; i++)
        {
            ans.push_back( binar(s[i],p,success) );
        }
        return ans;
    }
};