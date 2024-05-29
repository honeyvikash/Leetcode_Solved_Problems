class Solution {
public:
    int numSteps(string s) {
        int cnt=0;
        while(s!="1")
        {
            if(s.back()=='1')
            {
                int idx=-1;
                for(int i = s.length()-2 ; i >=0 ; --i)
                    if(s[i]=='0')
                    {
                        idx = i;
                        break;
                    }
                    else
                    {
                        if(i>=0)s[i] = '0';
                    }
                if(idx==-1)
                    s.insert(s.begin(),'1');
                else
                    s[idx] = '1';
                s.back() = '0';
            }
            else
                s.pop_back();

            cnt++;
        }
        return cnt;
    }
};