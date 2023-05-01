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
    TreeNode* res= new TreeNode(-1);
    TreeNode* result=res;
void inorder(TreeNode* root){
    if(root==NULL)
    return ;
    inorder(root->left);
    TreeNode* temp=new TreeNode(root->val);
    res->right=temp;
    res=temp;
    inorder(root->right);
}
public:
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return result->right;
    }
};

// Second Approach
class Solution {
    public:
    TreeNode* increasingBST(TreeNode* root,TreeNode* tail=NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};