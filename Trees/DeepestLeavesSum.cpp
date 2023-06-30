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
    int s=0;
    void sum(TreeNode* root,int h){
        if(root==NULL)
        return ;
        if(root->left==NULL&&root->right==NULL&&h!=0){
            return ;
        }
        if(root->left==NULL&&root->right==NULL&&h==0){
            s+=root->val;
            return ;
        }
        h--;
        if(root->left)
        sum(root->left,h);
        if(root->right)
        sum(root->right,h);
    }
    int height(TreeNode* root){
        if(root==NULL)
        return 0;
        return 1+max(height(root->left),height(root->right));
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root);
        h--;
        sum(root,h);
        return s;
    }
};