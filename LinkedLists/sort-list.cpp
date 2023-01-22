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
    ListNode* sortList(ListNode* head) {
        // Approach - 1 Using Map to keep values sorted
        map<int,int> s;
        ListNode* cur=head;
        while(cur){
            // There can be multiple same values
            if(s.find(cur->val)!=s.end()){
                s[cur->val]++;
            }else{
                s[cur->val]=1;
            }
            cur=cur->next;
        }
        cur=head;
        while(cur){
            cout<<s.begin()->first<<" ";
            cur->val=s.begin()->first;
            s[cur->val]=s[cur->val]-1;
            if(s[cur->val]==0)
            s.erase(cur->val);
            cur=cur->next;
        }
        return head;
        // Approach - 2 Using vector
        vector<int> values;
        ListNode* cur=head;
        while(cur){
            values.push_back(cur->val);
            cur=cur->next;
        }
        sort(values.begin(),values.end());
        cur=head;
        int index=0;
        while(cur){
            cur->val=values[index++];
            cur=cur->next;
        }
        return head;
    }
};
