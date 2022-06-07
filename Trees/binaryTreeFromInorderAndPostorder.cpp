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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return NULL;
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    
    TreeNode* build(vector<int>& inorder,int is,int ie, vector<int>& postorder,int ps,int pe){
        if(ps>pe||is>ie)
            return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int n = inorder.size();
        int inRoot = find(inorder,n,postorder[pe]); 
        int numsleft = inRoot - is;
        root->left = build(inorder,is,inRoot-1,postorder,ps,ps+numsleft-1);
        root->right = build(inorder,inRoot+1,ie,postorder,ps+numsleft,pe-1);
        return root;
    }
};