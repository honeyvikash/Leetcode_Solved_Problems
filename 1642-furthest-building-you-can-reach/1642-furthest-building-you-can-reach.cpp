class Solution {
public:
    bool possible(int x,vector<int>heights, int bricks, int ladders)
    {
        vector<int>adj_difference;
        for(int i=0;i<x;i++)
        {
            if(heights[i+1]>heights[i])
            {
                adj_difference.push_back(heights[i+1]-heights[i]);
            }
        }
        sort(adj_difference.begin(),adj_difference.end(),greater<int>());
        for(int i=adj_difference.size()-1;i>=0;i--)
        {
            bricks-=adj_difference[i];
            // cout<<bricks<<endl;
            if(bricks<0)
            {
                break;
            }
            else
            {
                adj_difference.pop_back();
            }
        }
        return adj_difference.size()<=ladders?1:0;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // Binary Search Approach
        // int n = heights.size();
        // int l=0,h=n;
        // while(l<h-1)
        // {
        //     int m=l+(h-l)/2;
        //     if(possible(m,heights,bricks,ladders)) l =m;
        //     else h=m;
        // }
        // return l;
        
        //pq approach
        
        priority_queue<int> pq;
        int idx=0; 
        for(idx=0; idx<heights.size()-1; idx++)
        { 
            int adj_difference = heights[idx+1]-heights[idx];
            
            if(adj_difference <= 0)
            {
                continue;
            }
            
            bricks -= adj_difference; 
            pq.push(adj_difference);
            
            if(bricks < 0)
            {
                bricks += pq.top(); 
                pq.pop(); 
                ladders--;
            }
            if(ladders < 0) break;
        }
        return idx;
    }
};