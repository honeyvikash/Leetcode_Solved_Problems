class Solution {
public:
    int getMinSwaps(string num, int k) {
        string s = num;
        while(k--)
        {
            next_permutation(s.begin(),s.end());
        }
        
        // cout<<s<<endl;
        
        int cnt=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=num[i])
            {
                int j=i+1;
                while(s[j]!=num[i])j++;
                cnt+=j-i;
                while(j--!=i)
                {
                    swap(s[j],s[j+1]);
                }
            }
        }
        return cnt;
    }
};
