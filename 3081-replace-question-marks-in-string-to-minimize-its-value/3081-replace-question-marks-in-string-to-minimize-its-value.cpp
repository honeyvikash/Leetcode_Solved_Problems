class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.size();
        map<char,int> mp,asg;
        for(char a = 'a' ; a <= 'z' ; ++a)
            mp[a] = 0;
        for(auto&a:s)
            mp[a]++;
        
        if(mp['?'] == 0)
        {
            return s;
        }
        else
        {
            priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
            for(auto &[a,b]:mp)
            {
                if(a!='?')
                {
                    pq.push({b,a});
                }
            }
            int k = mp['?'];
            
            while(k--)
            {
                auto tp = pq.top();
                pq.pop();
                
                asg[tp.second]++;
                pq.push({tp.first+1,tp.second});
            }
            
        }
        for(auto&a:s)
        {
            if(a=='?')
            {
                for(auto&[c,d]:asg)
                {
                    if(d>0)
                    {
                        a = c;
                        d--;
                        break;
                    }
                }
            }
        }
        return s;
    }
};