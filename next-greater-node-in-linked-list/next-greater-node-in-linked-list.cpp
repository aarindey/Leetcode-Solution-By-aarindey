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
    vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ans;
    if(!head)
    return ans;
    ListNode* temp;
    bool entered=false;
    while(head->next!=NULL)
    {
    temp=head;
    while(temp!=NULL)
    {
        entered=false;
        temp=temp->next;
        if(temp&&temp->val>head->val)
        {
            ans.push_back(temp->val);
            entered=true;
            break;
        }
    }
    if(!entered)
    ans.push_back(0);   
    head=head->next;
    }
    ans.push_back(0);
    return ans;
    }
};