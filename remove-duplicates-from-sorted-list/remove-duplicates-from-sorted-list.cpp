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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp;
        temp=head;
        while(temp!=NULL)
        {  
            if(temp->next!=NULL&&temp->val==temp->next->val)
            {ListNode* t;
             t=temp->next;
                temp->next=temp->next->next;
             t->next=NULL;
            delete t;
             continue;
            }
            temp=temp->next;
            
        }
        return head;
    }
};