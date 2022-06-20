/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        int m=0,n=0;
        if(a==NULL||b==NULL)
            return NULL;
        while(a)
        {
            m++;
            a=a->next;
        }
        while(b)
        {
            n++;
            b=b->next;
        }
        a=headA;
        b=headB;
        if(m>n)
        {
            for(int i=0;i<m-n;i++)
            {
                a=a->next;
            }
        }
        else if(n>m)
        {
            for(int i=0;i<n-m;i++)
            {
                b=b->next;
        }
        }
        while(a!=b)
        {
           
            a=a->next;
            b=b->next;
        }
        if(a==b)
        return a;
       
        
        return NULL;
    }
};