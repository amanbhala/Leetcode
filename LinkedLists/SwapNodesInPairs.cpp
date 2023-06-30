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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp&&temp->next){
            ListNode* first=temp;
            ListNode* second=temp->next;
            if(second->next!=NULL){
                ListNode* ref=second->next;
                first->next=ref;
                second->next=first;
                temp=ref;
            }else{
                first->next=NULL;
                second->next=first;
                temp=NULL;
            }
            if(prev!=NULL){
                prev->next=second;
            }else{
                head=second;
            }
            prev=first;
        }
        return head;
    }
};