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
// BFS 
class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)
        return 0;
        queue<Node*>q;
        q.push(root);
        int result=0;
        while(!q.empty()){
            int count=q.size();
            while(count--){
                Node* temp=q.front();
                q.pop();
                if(temp->children.size()!=0){
                    vector<Node*> v=temp->children;
                    for(auto node: v){
                        q.push(node);
                    }
                }
            }
            result++;
        }
        return result;
    }
};
// DFS
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        int depth = 0;
        for (auto child : root->children) depth = max(depth, maxDepth(child));
        return 1 + depth;
    }
};