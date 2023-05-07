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
//  Using Recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        return NULL;
        TreeNode* l=invertTree(root->left);
        TreeNode* r=invertTree(root->right);
        root->left=r;
        root->right=l;
        return root;
    }
};
// Using Stack
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        return NULL;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp=s.top();
            s.pop();
            TreeNode* left=temp->left;
            temp->left=temp->right;
            temp->right=left;
            if(temp->left)
            s.push(temp->left);
            if(temp->right)
            s.push(temp->right);   
        }
        return root;
    }
};
// Using Queue
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        return NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            TreeNode* left=temp->left;
            temp->left=temp->right;
            temp->right=left;
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);   
        }
        return root;
    }
};