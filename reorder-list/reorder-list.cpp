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
#include<vector>
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* temp=head;
        int l=0;
        while(temp)
        {
            ListNode* t=temp;
            v.push_back(t);
            temp=temp->next;
            l++;
        }
        ListNode* ptr=head;
        ListNode* pptr=ptr;
        int i=0,j=v.size();
        int c=1;
        while(c!=l)
        {
            pptr->next=v[--j];
            pptr=pptr->next;
            c++;
            if(c==l)
            break;
            pptr->next=v[++i];
            pptr=pptr->next;
            c++;
        }
        pptr->next=NULL;
        head=ptr;
    }
};