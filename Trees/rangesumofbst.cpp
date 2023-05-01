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
// By Using extra space, storing all the values in an array and then sum them
class Solution {
    void inorder(TreeNode* root, int low, int high, vector<int>&values){
        if(root==NULL)
        return ;
        if(root->left)
        inorder(root->left,low,high,values);
        values.push_back(root->val);
        if(root->right)
        inorder(root->right,low,high,values);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>values;
        inorder(root,low,high,values);
        int result=0;
        for(int i=0;i<values.size();i++){
            if(values[i]==low){
                while(values[i]!=high){
                    result+=values[i];
                    i++;
                }
                result+=values[i];
                break;
            }
        }
        return result;
    }
};
// No extra space is used, variable if passed and value is added if it lies in between low and high
class Solution {
    void inorder(TreeNode* root, int low, int high, int& result){
        if(root==NULL)
        return ;
        if(root->left)
        inorder(root->left,low,high,result);
        if(root->val>=low&&root->val<=high)
        result+=root->val;
        if(root->right)
        inorder(root->right,low,high,result);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result=0;
        inorder(root,low,high,result);
        return result;
    }
};
// Simple resursive solution 
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if( root == NULL) return 0;
        int n  = 0;
        if(root->val >= low && root->val <= high) n = root->val;
        n += rangeSumBST(root->left, low, high);
        n += rangeSumBST(root->right, low, high);
        return  n;
    }
};