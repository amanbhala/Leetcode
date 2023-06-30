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
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        int count=0;
        vector<int>v;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
            count++;
        }
        int result=INT_MIN;
        for(int i=0;i<count/2;i++){
            result=max(result,v[i]+v[count-i-1]);
        }
        return result;
    }
};