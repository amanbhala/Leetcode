/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<pair<Node* , int> > q;
        q.push({root,1});
        pair<Node* ,int> front;
        pair<Node* ,int> temp;
        int level=1;
        while(!q.empty()){
            front = q.front();
            q.pop();
            if(!q.empty()){
                temp = q.front();
                if(temp.second==front.second){
                    front.first->next=temp.first;
                }
            }
            if(front.first->left){
                    level=front.second;
                    level++;
                    q.push({front.first->left,level});
            }
            if(front.first->right){
                    q.push({front.first->right,level});
            }
        }
        return root;
    }
};