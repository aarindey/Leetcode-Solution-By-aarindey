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
    stack<int> ListToStack(ListNode* node)
    {
        stack<int> s;
        while(node)
        {
            s.push(node->val);
            node=node->next;
        }
        return s;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        s1=ListToStack(l1);
        s2=ListToStack(l2);
        int carry=0;
        ListNode* current=NULL;
        while(!s1.empty()||!s2.empty()||carry!=0)
        {
            int sum=carry;
            if(!s1.empty())
            {
                sum+=s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                sum+=s2.top();
                s2.pop();
            }
            ListNode* newNode=new ListNode(sum%10);
            newNode->next=current;
            current=newNode;
            carry=sum/10;
        }
        return current;
    }
};