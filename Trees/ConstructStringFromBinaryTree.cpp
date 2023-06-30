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
public:
    string tree2str(TreeNode* root) {
        string res="";
        calculate(root,res);
        // remove the first and last parentheses from the output string
        res.erase(res.begin());
        res.erase(res.begin()+res.length()-1);
        return res;
    }
    void calculate(TreeNode* root, string& res){
        if(root==NULL)
        return ;
        res+='('+to_string(root->val);
        if(root->left==NULL&&root->right!=NULL){
            res+="()";
        }
        calculate(root->left,res);
        calculate(root->right,res);
        res+=')';
    }
};