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
// First Solution
class Solution {
    void traversal(Node* root, vector<int>&res) {
        if(root==NULL)
        return ;
        vector<Node*>temp=root->children;
        for(auto a: temp){
            traversal(a,res);
            res.push_back(a->val);
        }
    }
public:
    vector<int> postorder(Node* root) {
        vector<int>res={};
        if(root==NULL)
        return {};
        traversal(root,res);
        res.push_back(root->val);
        return res;
    }
};
// Second Solution
class Solution {
public:
vector<int> ans;
    void traverse(Node* root) {
        if(root==nullptr){
            return;
        }
        for(auto c: root->children){
            traverse(c);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        traverse(root);
        return ans;
    }
};
// third Solution
class Solution {
public:
vector<int> postorder(Node* root) {
    if(root==NULL) return {};
    vector<int> res;
    stack<Node*> stk;
    stk.push(root);
    while(!stk.empty())
    {
        Node* temp=stk.top();
        stk.pop();
        for(int i=0;i<temp->children.size();i++) stk.push(temp->children[i]);
        res.push_back(temp->val);
    }
    reverse(res.begin(), res.end());
    return res;
}
};