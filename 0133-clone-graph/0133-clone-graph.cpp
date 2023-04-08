/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int,Node*> ump;
public:
    Node* dfs(Node *node,vector<bool> &visited){
        if( NULL==node )    return node;
        visited[node->val] = true;
        Node *copyNode = new Node(node->val);
        ump[copyNode->val] = copyNode;
        for(auto neighbor : node->neighbors){
            if( false==visited[neighbor->val] )
                dfs(neighbor,visited);
            copyNode->neighbors.push_back(ump[neighbor->val]);
        }
        return copyNode;
    }
    Node* cloneGraph(Node* node) {
        vector<bool> visited(101,false);
        return dfs(node,visited);
    }
};