class Solution {
public:
    int maximumTop(vector<int>& a, int k) {
        int n = a.size();
        if(n==1 && k==1)return -1;
        if(n==1 && (k%2==1)) return -1;
        
        priority_queue<int>p;
        
        //threee cases:
        //1
        
        if(n>k)
        {
            for(int i=0;i<k-1;i++)
            {
                p.push(a[i]);
            }
            //aisa isliye ki ye test case chala ke dekho
            //[5,2,9,4,0,6] k=3
            p.push(a[k]);
            return p.top();
        }
        
        //2
        if(n==k)
        {
            for(int i=0;i<n-1;i++)
            {
                p.push(a[i]);
            } 
             return p.top();
        }
        
        //3
        if(n<k)
        {
            for(int i=0;i<n;i++)
            {
                p.push(a[i]);
            }
            return p.top(); 
        }
        
        //return kuchhbi if alredy handled
        return 9;
    }
};