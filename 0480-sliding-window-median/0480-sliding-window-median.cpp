class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& n, int k) {
        vector<double> ans;
        vector<int> window;
        int len = n.size();
        for(int i=0;i<k;i++) window.push_back(n[i]);
        sort(window.begin(),window.end());
        if(k%2==0) ans.push_back(((long long)window[k/2]+(long long)window[k/2-1])/2.00);
        else ans.push_back(double(window[k/2]));
        for(int i=1;i<=len-k;i++)
        {
            int prev = n[i-1], nxt = n[i+k-1];
            
            for(int j=0;j<k;j++)   if(window[j]==prev){window[j]=nxt;  break;}
            sort(window.begin(),window.end());
            
            if(k%2==0)  ans.push_back(((long long)window[k/2]+(long long)window[k/2-1])/2.00);
            else ans.push_back(double(window[k/2]));
        }
        return ans;
    }
};