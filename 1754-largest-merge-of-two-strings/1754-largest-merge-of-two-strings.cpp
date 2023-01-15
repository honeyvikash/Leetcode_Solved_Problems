class Solution {
public:
    string largestMerge(string w1, string w2) {
        // string s="";
        // int i=0;
        // int j=0;
        // int n1=w1.size(),n2=w2.size();
        // while(i<n1 && j<n2)
        // {
        //     if(w1[i]<w2[j])
        //     {
        //         s+=w2[j++];
        //     }
        //     else if(w1[i]>w2[j])
        //     {
        //         s+=w1[i++];
        //     }
        //     else
        //     {
        //         int t1=i,t2=j;
        //         int flag=0;
        //         while(t1<n1 && t2<n2)
        //         {
        //             if(w1[t1]==w2[t2])
        //             {
        //                 t1++;
        //                 t2++;
        //             }
        //             else if(w1[t1]>w2[t2])
        //             {
        //                 flag=1;
        //                 break;
        //             }
        //             else
        //             {
        //                 flag=2;
        //                 break;
        //             }
        //         }
        //         if(!flag)
        //         {
        //             flag=2?t1==n1:1;
        //         }
        //         if(flag==1)
        //         {
        //             s+=w1[i++];
        //         }
        //         else
        //         {
        //             s+=w2[j++];
        //         }
        //     }
        // }
        // while(i<n1)s+=w1[i++];
        // while(j<n2)s+=w2[j++];
        // return s;
    
        string ans="";
        while(!w1.empty() && !w2.empty())
        {
            if(w1.front()>w2.front())
            {
                 ans.push_back(w1.front());
                w1.erase(w1.begin());
            }
             else if(w1.front()<w2.front()){
                ans.push_back(w2.front());
                w2.erase(w2.begin()); 
            }
            else
            {
                if(w1>=w2)
                {
                    ans.push_back(w1.front());
                    w1.erase(w1.begin()); 
                }
                else
                {
                      ans.push_back(w2.front());
                    w2.erase(w2.begin()); 
                }
            }
         
        }
       ans+=w1;
       ans+=w2;
       return ans;
    }
};