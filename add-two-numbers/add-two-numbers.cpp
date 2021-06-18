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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
        return l2;
        if(l2==NULL)
        return l1;
        int carry=0,sum;
        ListNode* head=NULL;
        while(l1&&l2)
        {
            sum=l1->val+l2->val+carry;
            ListNode* n=new ListNode(sum%10);
            carry=sum/10;
            n->next=head;
            head=n;
            l1=l1->next;
            l2=l2->next;
        }   
        while(l1)
        {
             sum=l1->val+carry;
             ListNode* n=new ListNode(sum%10);
             carry=sum/10;
             n->next=head;
             head=n;  
             l1=l1->next;
        }
        while(l2)
        {
            sum=l2->val+carry;
            ListNode* n=new ListNode(sum%10);
            carry=sum/10;
            n->next=head;
            head=n;  
            l2=l2->next;
        }
        if(carry>0)
        {
            ListNode* n=new ListNode(carry);
            n->next=head;
            head=n;
        }   
        //Reversing the linked list
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr)
        {
            ListNode* n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        head=prev;
        return head;
    }
};