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
       if(!head)
       return NULL;
       if(!head->next)
       return head;
       int value=head->val;
        ListNode* curr=head->next;
        if(curr->val==value)
        {
            while(curr&&curr->val==value)
            {
                curr=curr->next;
            }
            return deleteDuplicates(curr);
        }
        else
        {
            head->next=deleteDuplicates(curr);
            return head;
        }
    }
};