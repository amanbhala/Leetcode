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
//  Store sequences and then compare
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>r1;
        vector<int>r2;
        calculate(r1,root1);
        calculate(r2,root2);
        return r1==r2;
    }
    void calculate(vector<int>&r,TreeNode* root){
        if(root==NULL)
        return ;
        if(root->left==NULL&&root->right==NULL){
            r.push_back(root->val);
            return ;
        }
        calculate(r,root->left);
        calculate(r,root->right);
    }
};
// Store tree1's sequences and compare the result as you run
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>r1;
        calculate(r1,root1);
        bool result=false;
        if(compare(root2,r1)&&r1.size()==0)
        // There can be cases when tree2's sequence is same as tree1's sequence but there are some characters left in tree1
            result=true;
        return result;
    }
    void calculate(vector<int>&r, TreeNode* root){
        if(root==NULL)
        return ;
        if(root->left==NULL&&root->right==NULL){
            r.push_back(root->val);
            return ;
        }
        calculate(r,root->left);
        calculate(r,root->right);
    }
    bool compare(TreeNode* root, vector<int>&r1){
        if(root==NULL)
        return true;
        if(root->left==NULL&&root->right==NULL){
            // removing first element from the vector everytime we have compare it and it is same
            if(r1.size()==0||root->val!=r1[0]){
                return false;
            }else{
                r1.erase(r1.begin());
                return true;
            }
        }
        return compare(root->left,r1) && compare(root->right,r1);
    }
};