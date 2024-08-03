class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        // if(n==1){
        //     return target[0]==arr[0];
        // }
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());

        for(int i=0;i<n;i++)
        {
            if(arr[i] != target[i])
            {
                return false;
            }
        }
        return true;
    }
};