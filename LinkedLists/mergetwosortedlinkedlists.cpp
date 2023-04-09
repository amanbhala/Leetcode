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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans;
        ListNode* head;
        if(list1==NULL){
            return list2;
        }else if(list2==NULL){
            return list1;
        }else if(list1==NULL&&list2==NULL){
            return NULL;
        }else{
            ListNode* temp1=list1;
            ListNode* temp2=list2;
            if(temp1->val<=temp2->val){
                ans=temp1;
                head=ans;
                temp1=temp1->next;
            }else{
                ans=temp2;
                head=ans;
                temp2=temp2->next;
            }
            while(temp1&&temp2){
                if(temp1->val<=temp2->val){
                    ans->next=temp1;
                    ans=temp1;
                    temp1=temp1->next;
                }else{
                    ans->next=temp2;
                    ans=temp2;
                    temp2=temp2->next;
                }
            }
            if(temp1!=NULL&&temp2==NULL){
                ans->next=temp1;
            }else if(temp2!=NULL&&temp1==NULL){
                ans->next=temp2;
            }
        }
        return head;
    }
};