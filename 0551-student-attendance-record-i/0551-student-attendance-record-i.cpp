class Solution {
public:
    bool checkRecord(string s) {
        bool check1 = true ;

        int cnt = 0 ;
        for(auto it : s)
        {
            if(it=='A') cnt++ ;
        }

        check1 = cnt<2 ;

        bool check2 = true ;

        int i=0 ; 
        int n = s.size() ;
        while(i<n)
        {
            char ch = s[i] ;
            if(ch!='L') {
                i++ ;
                continue ;
            } 

            int j=i+1 ;
            int streak = 1 ;
            while(j<n && s[j]==ch)
            {
                streak++ ;
                j++ ;
            }

            cout<<streak<<endl;

            j-- ;
            if(streak>=3) check2 = false ;

            i=j+1 ;
        }

        return check1 && check2 ;
    }
};