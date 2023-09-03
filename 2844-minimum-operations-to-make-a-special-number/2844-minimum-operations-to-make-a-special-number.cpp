class Solution {
public:
    int minimumOperations(string num) {
        int cnt1 = 0;
        int n = num.size();
        int cnt = 0;
        int id1,id2;
        int ans = INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            if(num[i]=='0' && cnt==0)
            {
                cnt++;
                id1 = i;
            }
            else if(num[i]=='0' && cnt==1)
            {
                cnt++;
                id2 = i;
                break;
            }
            if(num[i]=='5' && cnt==1)
            {
                cnt++;
                id2 = i;
                break;
            }
        }
        
        if(cnt==2)
        {
            // cout<<id1<<" "<<id2<<" ";
            int tmp = n-id1-1;
            tmp+=(id1-id2)-1;
            ans = tmp;
        }
        else if(cnt==1)
        {
            ans = n-1;
        }
        cnt = 0;
        id1 = 0,id2 = 0;

        for(int i=n-1;i>=0;i--)
        {
            if(num[i]=='5' && cnt==0)
            {
                cnt++;
                id1 = i;
            }
            if((num[i]=='2' || num[i]=='7') && cnt==1)
            {
                cnt++;
                id2 = i;
                break;
            }
        }
        if(cnt==2)
        {
            // cout<<id2<<" ";
            int tmp = n-id1-1;
            tmp+=(id1-id2)-1;
            ans = min(ans,tmp);
        }
        if(ans == INT_MAX) 
            return n;
        return ans;
    }
};