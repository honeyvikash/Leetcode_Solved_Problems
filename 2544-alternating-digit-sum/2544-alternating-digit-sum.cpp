class Solution {
public:
    int alternateDigitSum(int n) {
        stack<int>s;
        while(n>0)
        {
            s.push(n%10);
            n/=10;
        }
        int k=0;
        int ans=0;
        while(!s.empty())
        {
            if(k%2==0)
            {
                ans+=s.top();
            }
            else
            {
                ans-=s.top();
            }
            s.pop();
            k++;
        }
        return ans;
    }
};