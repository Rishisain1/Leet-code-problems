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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode* curr=head;
        while(curr!=NULL){
            n++;
            curr=curr->next;
        }
        n=n/k;
        ListNode* next;
        ListNode* lastTail=NULL;
        curr=head;
        for(int i=0;i<n;i++){
            ListNode* temp=curr;
            ListNode* prev=NULL;
            for(int j=0;j<k;j++){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            if(i==0)head=prev;
            else{
                lastTail->next=prev;
            }
            lastTail=temp;
        }
        lastTail->next=next;
        return head;
    }
};