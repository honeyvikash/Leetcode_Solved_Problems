class Solution {
public:
// int common(string s1, int n1, string s2, int n2)
// {
//     int freq1[26] = { 0 };
//     int freq2[26] = { 0 };
//     int i, count = 0;
//     for (i = 0; i < n1; i++)
//         freq1[s1[i] - 'a']++;
//     for (i = 0; i < n2; i++)
//         freq2[s2[i] - 'a']++;
//     for (i = 0; i < 26; i++)
//     {
//         if(count==1)break;
//         count += (min(freq1[i], freq2[i]));
//     }
//     return count;
// }

    bool isSame(string &a, string &b)
    {
        vector<bool> storage(26, false);
        for(int i = 0; i<a.size();i++){
            int tmp = a[i]-'a';
            storage[tmp] = true;
        }
        for(int i = 0;i<b.size();i++){
            int tmp = b[i]-'a';
            if(storage[tmp])
                return true;
        }
        return false;
    }

    int maxProduct(vector<string>& w) {
        // sort(w.begin(),w.end());
        // for(int i=0;i<w.size();i++)
        // {
        //     sort(w[i].begin(),w[i].end());
        // }
        // vector<int>ans;
        // for(int i=0;i<w.size();i++)
        // {
        //     string s1=w[i];
        //     for(int j=0;j<w.size();j++)
        //     {
        //         string s2=w[j];
        //         int n1 = s1.length(), n2 = s2.length();
        //         if(common(s1, n1, s2, n2)==0)
        //         {
        //             ans.push_back(n1*n2);
        //         }
        //     }
        // }
        // return ans.size()==0?0:(*max_element(ans.begin(),ans.end()));
        int ans = 0;
        for(int i = 0;i<w.size()-1;i++)
        {
            for(int j = i+1;j<w.size();j++)
            {
                int tmp = w[i].size()*w[j].size();
                if(tmp>ans && !isSame(w[i],w[j]))ans = tmp;
            }
        }
        return ans;
        
    }
};