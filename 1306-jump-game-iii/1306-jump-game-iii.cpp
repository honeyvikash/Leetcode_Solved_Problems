class Solution {
public:
    bool dfs(int idx,vector<int>& arr,int n,vector<int>&vis)
    {
        vis[idx]=1;
        if(arr[idx]==0)return true;
        
        int s = idx+arr[idx];
        int e = idx-arr[idx];
        
        if(s>=0 and s<n and !vis[s])
        {
            if(dfs(s,arr,n,vis))return true;
        }
        if(e>=0 and e<n and !vis[e])
        {
            if(dfs(e,arr,n,vis))return true;
        }
        
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>vis(n,0);
        return dfs(start,arr,n,vis);
    }
};