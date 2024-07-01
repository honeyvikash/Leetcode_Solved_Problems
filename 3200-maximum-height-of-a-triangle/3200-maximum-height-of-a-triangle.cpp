class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int x = red , y = blue;
        int ans = 0;
        for(int i = 1 ; i <= 100 ; ++i)
        { 
            if(i%2==0)
            {
                if(red>=i)
                {
                    red-=i;
                    ans = max(ans,i);
                }
                else
                {
                    break;
                }
                
            }
            else
            {
                
                if(blue>=i)
                {
                    blue-=i;
                    ans = max(ans,i);
                }
                else
                {
                    break;
                }
            }
        }
        
        for(int i = 1 ; i <= 100 ; ++i)
        {
            if(i%2==0)
            {  
                if(y>=i)
                {
                    y-=i;
                    ans = max(ans,i);
                }
                else
                {
                    break;
                }
                
            }
            else
            {
                if(x>=i)
                {
                    x-=i;
                    ans = max(ans,i);
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};