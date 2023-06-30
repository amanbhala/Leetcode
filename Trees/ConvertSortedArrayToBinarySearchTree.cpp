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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l=0,r=nums.size();
        return calculate(nums,l,r);
    }
    TreeNode* calculate(vector<int>& nums, int l, int r){
        if(l>=r)
        return NULL;
        int m=(l+r)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left=calculate(nums,l,m);
        root->right=calculate(nums,m+1,r);
        return root;
    }
};