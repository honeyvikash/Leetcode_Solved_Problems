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
void post(Node* root){
    if(root==NULL){
        return;
    }
    // Traverse all the children first
        for (Node* child : root->children) {
            post(child);
        }

    // Add the current node's value to the result
        ans.push_back(root->val);

}
    vector<int> postorder(Node* root) {
        post(root);
        return ans;
    }
};