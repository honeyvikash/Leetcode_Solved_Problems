class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k>=n)
            return *max_element(arr.begin(),arr.end());
        
        int i = 0,j = 1;
        int cnt = 0;
        int prev = -1;
        while(1)
        {
            if(arr[i]>arr[j])
            {
                if(prev==-1 || prev==arr[i])
                {
                    cnt++;
                    prev = arr[i];
                }
                else
                {
                    cnt = 1;
                    prev = arr[i];
                }
                arr.push_back(arr[j]);
                if(j>i)
                    j++;
                else 
                    j = i+1;
            }
            else
            {
                if(prev==-1 || prev==arr[j])
                {
                    cnt++;
                    prev = arr[j];
                }
                else
                {
                    cnt = 1;
                    prev = arr[j];
                }
                arr.push_back(arr[i]);
                if(i>j)
                    i++;
                else
                    i = j+1;
            }
            if(cnt>=k)
                return prev;
        }
        return 0;
    }
};