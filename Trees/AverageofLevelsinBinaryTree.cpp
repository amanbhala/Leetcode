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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL)
        return {};
        vector<double> result;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int count=q.size();
            // long long int sum=0;
            long sum=0;
            int number=count;
            while(count--){
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            // result.push_back(double(sum)/double(number));
            result.push_back(sum*1.0/number);
        }
        return result;
    }
};