/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// First Approach
class Solution {
    TreeNode* result=NULL;
    void traversal(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original==target){
            result=cloned;
            return ;
        }
        if(original->left)
        traversal(original->left, cloned->left, target);
        if(original->right)
        traversal(original->right, cloned->right, target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        traversal(original,cloned,target);
        return result;
    }
};
// Second approach
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL||original==target)
        return cloned;
        TreeNode* res = getTargetCopy(original->left,cloned->left,target);
        if(res!=NULL)
        return res;
        return getTargetCopy(original->right,cloned->right,target);
    }
};