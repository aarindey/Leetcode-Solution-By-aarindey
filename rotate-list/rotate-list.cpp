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
    ListNode* rotateRight(ListNode* head, int k) {
    ListNode* temp=head;
        int l=0;
        if(head==NULL)
        return NULL;
        if(k==0)
        return head;        
    while(temp->next!=NULL)
    {
        temp=temp->next;
        l++;
    }
        l++;
        if(l==2)
        {
            if(k%2==0)
            {
                return head;
            }
            else
            {
                temp=head;
                head=head->next;
                head->next=temp;
                temp->next=NULL;
                return head;
            }
        }
        int i=1;
        while(true)
        {
            if(i*l-k>0)
            {
                k=i*l-k-1;
                break;
            }
            i++;
        }
    temp->next=head;
        while(k--)
        {
            head=head->next;
        }
        temp=head;
        head=head->next;
        temp->next=NULL;
        return head;
    }
};