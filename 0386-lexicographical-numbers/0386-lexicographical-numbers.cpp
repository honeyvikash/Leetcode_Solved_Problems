class Solution {
public:
    vector<int> lexicalOrder(int n) {
    vector<int> ans;
    int p = 1;
    for(int i = 1; i <= n; i++) 
    {
        ans.push_back(p);
        if(p*10 <= n) 
        {
            p *= 10;
        } else if(p%10 != 9 && p+1 <= n) {
            p++;
        } 
        else 
        {
            while((p/10) % 10 == 9) 
            {
                p /= 10;
            }
            p = p/10 + 1;
        }
    }
    return ans;
}

};