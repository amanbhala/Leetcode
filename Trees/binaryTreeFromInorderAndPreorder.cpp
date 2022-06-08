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
    
    int find(vector<int>& inorder, int n , int value){
        int index;
        for(index=0;index<n;index++){
            if(inorder[index]==value)
                break;
        }   
        return index;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if(inorder.size()!=preorder.size())
            return NULL;
        return build(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,n);
    }
    
    TreeNode* build(vector<int>& inorder,int is,int ie, vector<int>& preorder,int ps,int pe,int n){
        if(ps>pe||is>ie)
            return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int inRoot = find(inorder,n,preorder[ps]); 
        int numsleft = inRoot - is;
        root->left = build(inorder,is,inRoot-1,preorder,ps+1,ps+numsleft,n);
        root->right = build(inorder,inRoot+1,ie,preorder,ps+numsleft+1,pe,n);
        return root;
    }
};