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
        ListNode* slow=head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* fast=head->next;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
            curr->next=prev;
            prev=curr;
            curr=slow;
        }
        fast=slow->next;
        curr->next=prev;
        int ans=INT_MIN;
        while(slow!=NULL){
            ans=max(ans,slow->val+fast->val);
            slow=slow->next;
            fast=fast->next;
        }
        return ans;

    }
};