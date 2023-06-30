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
    int minimum=INT_MAX;
    TreeNode* prev=NULL;
    void findMinimum(TreeNode* root){
        if(root->left) findMinimum(root->left);
        if(prev)minimum=min(minimum,abs(root->val-prev->val));
        prev=root;
        if(root->right) findMinimum(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL)
        return 0;
        findMinimum(root);
        return minimum;
    }
};