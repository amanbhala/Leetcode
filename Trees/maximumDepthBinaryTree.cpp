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
    int maxDepth(TreeNode* root) {
        // Approach - 1 Recursive DFS
        if(root==NULL)
        return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
        // Aprrocah -2 Recursive DFS
        if(root==NULL){
            return 0;
        }
        int left= maxDepth(root->left);
        int right= maxDepth(root->right);
        return max(left,right)+1;
        // Approach - 3 BFS
        if(root==NULL)
        return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int ans=1;
        while(!q.empty()){
            pair<TreeNode*,int> temp=q.front();
            q.pop();
            if(temp.first->left){
                q.push({temp.first->left,temp.second+1});
                ans=temp.second+1;
            }
            if(temp.first->right){
                q.push({temp.first->right,temp.second+1});
                ans=temp.second+1;
            }   
        }
        return ans;
        // Approach - 4 BFS with loops
        if(root==NULL)
        return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            ans++; 
        }
        return ans;
        // Approach - 5 Iterative DFS
        if(root==NULL)
        return 0;
        stack<pair<TreeNode*,int>>s;
        int ans=0;
        s.push({root,1});
        while(!s.empty()){
            pair<TreeNode*,int> temp=s.top();
            s.pop();
            if (temp.first){
                ans=max(ans,temp.second);
                s.push({temp.first->left,temp.second+1});
                s.push({temp.first->right,temp.second+1});
            }
        }
        return ans;

    }
};
