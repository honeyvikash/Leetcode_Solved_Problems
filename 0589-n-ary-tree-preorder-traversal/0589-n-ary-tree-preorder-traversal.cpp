/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    void pot(Node* root)
    {
        if(!root)
            return;
        ans.push_back(root->val);
        for(auto a : root->children)
        {
            pot(a);
        }
    }
    vector<int> preorder(Node* root) {
        pot(root);
        return ans;
    }
};