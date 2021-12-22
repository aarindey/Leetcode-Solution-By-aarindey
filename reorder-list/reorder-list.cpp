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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        return;
        
        stack<ListNode*> st;
        ListNode* temp=head;
        int l=0;
        while(temp)
        {
            st.push(temp);
            temp=temp->next;
            l++;
        }
        temp=head->next;
        int c=1;
        ListNode *p;
        p=head;
        while(c!=l)
        {
            p->next=st.top();
            st.pop();
            p=p->next;
            c++;
            if(c==l)
            break;
            p->next=temp;
            p=p->next;
            temp=temp->next;
            c++;
        }
        p->next=NULL;
    }
};