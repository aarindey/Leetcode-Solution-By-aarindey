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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
      ListNode *temp1,*temp=list1,*temp2=list1;
        int c=0;
        while(list1!=NULL)
        {
            c++;
            if(c==a)
            {
            list1=list1->next;
            c++;
            temp->next=list2;
            break;
            }
            list1=list1->next;
            temp=temp->next;
        }
        while(list1!=NULL)
        {
            if(c==b+1)
            {   
                temp1=list1->next;
                list1->next=NULL;
                break;
            }
            c++;
            list1=list1->next;
        }
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=temp1;
        return temp2;
    }
};