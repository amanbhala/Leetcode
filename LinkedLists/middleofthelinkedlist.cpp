/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Approach -1 Two passes
        if(head==NULL)
        return NULL;
        ListNode* cur=head;
        int index=0;
        while(cur){
            index+=1;
            cur=cur->next;
        }
        index=index/2;
        cur=head;
        if(index%2){
            while(index--){
                cur=cur->next;
            }
            return cur;
        }
        while(index--){
            cur=cur->next;
        }
        return cur;
        // Approach -2 
    }
};
