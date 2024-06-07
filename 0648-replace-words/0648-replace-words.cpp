class Solution {
public:
    string replaceWords(vector<string>&d, string s) {
        set<string>st ;

        int n = s.size() ;
        vector<string>temp ;
        int i=0 ;
        string tem = "" ;
        while(i<n)
        {
            if(s[i]==' ')
            {
                temp.push_back(tem);
                tem="";
                i++;
            }
            else
            {
                tem+=s[i] ;
                i++ ;
            }
        }

        temp.push_back(tem) ;

        for(auto it : d) st.insert(it) ;
        string ans="" ;
        for(int i=0 ; i<temp.size() ; i++)
        {
            string str = temp[i] ;
            cout<<str<<" ";

            string t = "" ;
            int j ;
            for(j=0 ; j<str.size() ; j++)
            {
                t+=str[j] ;

                if(st.find(t)!=st.end()) {
                    cout<<t<<" ";
                    ans+=t ;
                    ans+=' ';
                    break ;
                }
            }
            if(j==str.size()) {
                ans+=t ;
                ans+=' ' ;
            }

        }

        ans.pop_back() ;
        return ans ;
    }
};