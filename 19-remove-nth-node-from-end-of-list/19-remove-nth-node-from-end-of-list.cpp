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
    if(head==NULL)
    return NULL;   
    ListNode new_head(-1);
    new_head.next=head;
    ListNode *fast=&new_head,*slow=&new_head;    
    for(int i=0;i<n;i++)  
    {
        fast=fast->next;
    }    
    while(fast->next)
    {
        fast=fast->next;
        slow=slow->next;
    }   
    ListNode* to_be_deleted=slow->next;
    slow->next=slow->next->next;
    delete to_be_deleted;    
    return new_head.next;    
    }
};