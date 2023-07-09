class Solution {
public:
    vector<int> freq;

    int a_minus_b(char a, char b, string& s) {
     //   cout<<a<<","<<b<<endl;
        int best_sum = 0;
        int a_count = 0, b_count = 0;
        for (char c : s) {
            if (c == a) a_count++;
            else if (c == b) b_count++;
            else continue;
            if (b_count > 0)
                best_sum = max(best_sum, a_count-b_count);
            else if ( b_count==0 ) //handle "bbaaaa" for previous b
                best_sum = max(best_sum, a_count-1);
            if (a_count < b_count ) {
                a_count = b_count = 0;
            }
        }
    //    cout<<best_sum<<endl;
        return best_sum;
    }

    int largestVariance(string s) {
        freq.assign(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        
        int ans = 0;
        for (char a = 'a'; a <= 'z'; a++) {
            for (char b = 'a'; b <= 'z'; b++) {
                if (freq[a-'a']>0 && freq[b-'a']>0 && a!=b)
                    ans = max(ans, a_minus_b(a, b, s));
            }
        }
        return ans;
    }
};