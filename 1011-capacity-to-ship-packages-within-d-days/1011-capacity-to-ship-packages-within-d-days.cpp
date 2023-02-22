class Solution {
public:
    bool isPossible(vector<int> &weights,int target,int days)
    {
        int currSum=0,currCount=1;
        for(int i=0 ; i<weights.size() && currCount<=days ; i++)
        {
            if( currSum+weights[i]<=target )
                currSum += weights[i];
            else
                currCount += 1,currSum = weights[i];
        }
        return currCount<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0,high=0,mid;
        
        for(int i=0 ; i<weights.size() ; i++)
        {
            low = max(low,weights[i]);
            high += weights[i];
        }
        int ans;
        while(low<=high)
        {
            mid = low+(high-low)/2;
            if( isPossible(weights,mid,days) )
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};