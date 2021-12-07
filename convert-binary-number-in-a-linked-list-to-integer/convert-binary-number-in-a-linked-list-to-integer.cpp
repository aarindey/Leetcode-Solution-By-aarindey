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
    int getDecimalValue(ListNode* head) {
        int sum=0,length=0;
    ListNode* temp;
        ListNode* temp2;
        temp=head;
        temp2=head;
        while(temp!=NULL)
        {
            
            temp=temp->next;
            length++;
        }
                while(temp2!=NULL)
        {
                    sum+=(temp2->val)*pow(2,(length-1));
                    length--;
            
            temp2=temp2->next;
        }
        return sum;
    }
};