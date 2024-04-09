class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q ;
        for(int i=0 ; i<tickets.size() ; i++)
        {
            q.push({tickets[i],i});
        }

        int time = 0 ;
        while(true)
        {
            int siz = q.size() ;
            while(siz--)
            {
                time++ ;
                auto it = q.front();
                int val = it.first ;
                int ind = it.second ;
                q.pop() ;
                val-- ;
                if(val!=0)
                {
                    q.push({val,ind});
                }
                else if(val==0 && k!=ind)
                {
                    continue ;
                }
                else if(val==0 && k==ind) return time ;
            }
        }

        return -1 ;
    }
};