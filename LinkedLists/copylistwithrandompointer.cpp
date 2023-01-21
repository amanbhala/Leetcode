/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur=head;
        Node* prev=NULL;
        unordered_map<Node*,Node*> m;
        Node* secondhead=NULL;   // This will be the head pointer of copied array.
        // Iterate through the linked list and make copied nodes.
        while(cur){
            Node* newNode = new Node(cur->val);
            // We will map the original node with the copied node, ex: 7->7, 13->13 
            m[cur]=newNode;
            if(prev){
                prev->next=newNode;
            }
            else{
                secondhead=newNode;
            }
            prev=newNode;
            cur=cur->next;
        }
        cur=head;
        // We will loop through our original linked list and then find the random pointer of each node and point the random pointer of each node in the copied list to the mapping of random pointer in the map. Example: 7's random pointer is NULL, we will find 7 of duplicated list from the map and then point to NULL in the duplicated list using the map again.  
        while(cur){
            Node* r=m[cur];
            Node* temp=cur->random;
            r->random=m[temp];
            cur=cur->next;
        }
        return secondhead;
    }
};
