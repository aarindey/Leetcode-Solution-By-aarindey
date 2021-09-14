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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            
    ListNode *finalHead;
 ListNode *finalTail;
if(l1==NULL)
    return l2;
        else if(l2==NULL)
            return l1;
        if(l1->val<l2->val)
        {
            finalHead=l1;
            l1=l1->next;
        }
            
        else
        {
            finalHead=l2;
            l2=l2->next;
        }
        finalTail=finalHead;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            { 
                
                finalTail->next=l1;
                l1=l1->next;

                
            }
            else
            {
                finalTail->next=l2;
                l2=l2->next;
               
            }
            finalTail=finalTail->next;
        }
        if(l2)
            finalTail->next=l2;
        else 
            finalTail->next=l1;
        return finalHead;
      
    }
};