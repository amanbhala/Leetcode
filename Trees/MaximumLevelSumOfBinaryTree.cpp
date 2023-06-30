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
    int bfs(TreeNode* root){
        long long int sum=INT_MIN;
        int ans=1;
        int level=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            long long int temp=0;
            for(int i=0;i<len;i++){
                TreeNode* t=q.front();
                q.pop();
                temp+=t->val;
                if(t->left)
                q.push(t->left);
                if(t->right)
                q.push(t->right);
            }
            if(temp>sum){
                sum=temp;
                ans=level;
            }
            level++;
        }
        return ans;
    }
public:
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)
        return 0;
        return bfs(root);
    }
};