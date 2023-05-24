bool cmp(pair<int,int> &left,pair<int,int> &right)
{
    return left.second>right.second;
}
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int,int>> vect;
        
        for(int i=0 ; i<nums1.size() ; i++)
        {
            vect.push_back({nums1[i],nums2[i]});
        }
        
        sort(vect.begin(),vect.end(),cmp);
        
        long long mn,ans=0,sum=0;
        
        priority_queue< int , vector<int> , greater<int> > minHeap;
        
        for(auto &val : vect)
        {
            mn = val.second;
            minHeap.push(val.first);
            sum += val.first;
            if( minHeap.size()>k )
            {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if( k==minHeap.size() )
            {
                ans = max(ans,mn*sum);
            }
        }
        return ans;
    }
};