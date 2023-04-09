/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Approach - 1 : Using a set, Space Complexity O(N), Time Cmplexity O(N)
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        set<ListNode* >s;
        while(head!=NULL){
            if(s.find(head)!=s.end()){
                return head;
            }
            s.insert(head);
            head=head->next;
        }
        return NULL;
        // Approach - 2: Using floyd cycle finding algorithm, Space Complexity O(1), Time Cmplexity O(N)
        ListNode* slow=head;
        ListNode* fast=head;
        bool cycle=false;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cycle=true;
                break;
            }
        }
        if(cycle){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
        return NULL;
    }
};