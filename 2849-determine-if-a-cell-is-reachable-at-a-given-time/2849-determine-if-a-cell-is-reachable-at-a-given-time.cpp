class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx>fx)
        {
            swap(sx,fx);
            swap(sy,fy);
        }
        int d1 = abs(sx-fx)+abs(sy-fy);
        int mind = min(abs(sx-fx),abs(sy-fy));
        int r = sx+mind;
        int c = sy>=fy?sy-mind:sy+mind;
        int ans = mind+abs(r-fx)+abs(c-fy);
        if(ans==t || d1==t)
            return true;
        if((ans<t || d1<t) && t!=1)
            return true;
        return false;
    }
};