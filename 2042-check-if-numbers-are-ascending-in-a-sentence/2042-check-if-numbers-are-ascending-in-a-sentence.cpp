class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        int mini=0;
        int no=0;
        int i=0;
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                no=0;
                while(isdigit(s[i]))
                {
                    no = no*10 + (s[i]-'0');
                    i++;
                }
                if(mini>=no)return false;
                
                mini = no;
            }
            
        }
        return true;
    }
};