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
        while(index--){
            cur=cur->next;
        }
        return cur;
        // Approach -2 Store O(N) Space Complexity solution
        vector<int> values;
        if(head==NULL)
        return NULL;
        ListNode* cur=head;
        while(cur){
            values.push_back(cur->val);
            cur=cur->next;
        }
        int index=values.size()/2;
        cur=head;
        while(index--){
            cur=cur->next;
        }
        return cur;
        // Approach -3 Using Two pointers
        if(head==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
