class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        int n=v.size();
        vector<int> ans(n);
        int positive = 0;    
        int negative = 1;

            for(int i=0;i<n;i++)
            {
                if(v[i]>0)
                {
                    ans[positive]=v[i]; 
                    positive+=2; 
                }
                else
                {
                    ans[negative]=v[i];
                    negative+=2; 
                }   
        }
        return ans;
    }
};