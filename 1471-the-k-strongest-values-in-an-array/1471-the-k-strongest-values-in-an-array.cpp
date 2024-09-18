class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int> ans;
        int med = arr[((n - 1) / 2)];

        int s = 0,e=n-1;
        for(int i=0;i<k;i++)
        {
            if(abs(arr[e]-med) >= abs(arr[s]-med))
            {
                ans.push_back(arr[e]);
                e--;
            }
            else
            {
                ans.push_back(arr[s]);
                s++;
            }
        }
        return ans;
    }
};