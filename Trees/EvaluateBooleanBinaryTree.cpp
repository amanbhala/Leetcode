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
 // Using Recursion 
class Solution {
    bool calculate(TreeNode* root){
        if(root->left==NULL&&root->right==NULL)
        return root->val;
        int l=calculate(root->left);
        int r=calculate(root->right);
        if(root->val==2){
            return l||r;
        }
        return l&&r;
    }
public:
    bool evaluateTree(TreeNode* root) {
        return calculate(root);
    }
};
// Using Switch statement 
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        switch(root->val) {
            case 0:
            case 1: return root->val;
            case 2: return evaluateTree(root->left) || evaluateTree(root->right);
            default: return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};
// Using ternary operator
class Solution {
public:
  bool evaluateTree(TreeNode* root) {
    if(!root->left && !root->right) return root->val;
    return (root->val == 2) ? evaluateTree(root->left) || evaluateTree(root->right) : evaluateTree(root->left)     && evaluateTree(root->right);
}
};
// Same recursive DFS solution, but different logic
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        // base case: leaf
        if (root->val < 2) return root->val;
        // or node
        else if (root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
        // and node
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};