class Solution {
public:
    int totalFruit(vector<int>& f) {
        int start=0,end=0,answer=0;
        unordered_map<int,int> m;
        while(end<f.size())
        {
            m[f[end]]++;
            if(m.size()<=2)
                answer=max(answer,end-start+1);  
            else
            {
                m[f[start]]--;
                if(m[f[start]]==0)
                    m.erase(f[start]);
                start++;
            }
            end++;
        }
        return answer;    
    }
};