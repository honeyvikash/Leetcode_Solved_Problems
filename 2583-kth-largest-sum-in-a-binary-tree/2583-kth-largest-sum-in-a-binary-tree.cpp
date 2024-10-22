/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    #define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define ll long long
#define all(a) (a).begin(), (a).end()
#define in insert
#define pb push_back
#define B break
#define C continue
#define F first
#define S second
    vector<vector<int>>ans;
    void LOT(TreeNode* &root)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int>temp;
            while (n--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node!=NULL)
                {
                    temp.push_back(node->val);
                    if (node->left)
                    {
                        q.push(node->left);
                    }
                    if (node->right)
                    {
                        q.push(node->right);
                    }
                }
                
            }
            ans.push_back(temp);
            temp.clear();
            
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
         LOT(root);
        if(root==NULL)
        {
            return {};
        }
        priority_queue<ll>pq;
        vector<ll>v;
        // for(auto &x:ans)
        // {
        //     ll a= accumulate(all(x),0ll);
        //     pq.push(a);
        // }
        if(ans.size()<k)return -1;
        for(auto &x:ans)
        {
            ll a= accumulate(all(x),0ll);
            v.pb(a);
        }
        sort(all(v));
//         while(!pq.empty())
//         {
//             if(k==0)B;
//             pq.pop();
//             k--;
            
//         }
        // return pq.top();
        ll pp=v[v.size()-1];
        for(int i=v.size()-1;i>=0;i--)
        {
            if(k==0)
            {
                B;
            }
            else
            {
                pp=v[i];
                k--;
            }
        }
        return pp;
        
    }
};