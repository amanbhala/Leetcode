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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans = {};
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> values = {};
            while(size!=0){
                TreeNode* front = q.front();
                q.pop();
                values.push_back(front->val);
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
                size--;
            }
            ans.push_back(values);
        }
        return ans;
}
};