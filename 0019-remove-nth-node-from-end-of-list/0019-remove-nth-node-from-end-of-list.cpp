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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return NULL;
        if(head->next==NULL&&n==1)return NULL;
        ListNode* next=head;
        ListNode* curr=head;
        ListNode* prev=head;
        for(int i=0;i<n;i++){
            next=next->next;
        }
        if(next==NULL){
            head=head->next;
            return head;
        }
        while(next!=NULL){
            prev=curr;
            next=next->next;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete curr;
        return head;
    }
};