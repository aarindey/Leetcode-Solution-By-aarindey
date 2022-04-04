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
    ListNode* swapNodes(ListNode* head, int k) {
    ListNode* temp=head;
    vector<int> v;
    while(temp!=NULL)
    {
        v.push_back(temp->val);
        temp=temp->next;
    }
        int n=v.size();
        swap(v[k-1],v[n-k]);
        ListNode* dummy=new ListNode(0);
        temp=dummy;
        for(int i=0;i<n;i++)
        {
            ListNode* t=new ListNode(v[i]);
            dummy->next=t;
            dummy=t;
        }
        dummy->next=NULL;
        return temp->next;
    }
};