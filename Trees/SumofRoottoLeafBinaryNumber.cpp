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
    int ans=0;
public:
    int sumRootToLeaf(TreeNode* root) {
        int curr=0;
        calculate(root,curr);
        return ans;
    }
    void calculate(TreeNode* root, int curr){
        if(root==NULL)
        return ;
        curr=(curr<<1)|root->val;
        if(root->left==NULL&&root->right==NULL){
            ans+=curr;
            return ;
        }
        calculate(root->left,curr);
        calculate(root->right,curr);
    }
};