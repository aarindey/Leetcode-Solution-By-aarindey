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
    ListNode* partition(ListNode* head, int x) {
        ListNode *LH=NULL,*LT=NULL,*RH=NULL,*RT=NULL;
        ListNode* A=head;
        while(A)
        {
            if(A->val<x)
            {
             if(LH==NULL)
              {
                 LH=A;
                 LT=A;
              } 
              else 
              {
                  LT->next=A;
                  LT=A;
              }   
            }
            else
            {
                if(RH==NULL)
              {
                 RH=A;
                 RT=A;
              } 
              else 
              {
                  RT->next=A;
                  RT=A;
              }  
            }
           A=A->next;        
        }
        if(LH==NULL&&RH!=NULL)
        {
            RT->next=NULL;
            return RH;
        }
        else if(LH!=NULL&&RH==NULL)
        {
            LT->next=NULL;
            return LH;
        }
        else if(LH&&RH)
        {
            LT->next=RH;
            RT->next=NULL;
        }
        return LH;
    }
};