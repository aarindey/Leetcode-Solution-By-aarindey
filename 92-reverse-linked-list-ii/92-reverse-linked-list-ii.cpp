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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    
        vector<int> v;
        ListNode* temp=head;
        while(temp)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        if(v.size()==1)
        return head;
        left--;
        right--;
        while(left<right)
        {
            swap(v[left],v[right]);
            left++;
            right--;
        }
        ListNode* dummy=new ListNode(0);
        ListNode* prev=new ListNode(v[0]);
        dummy->next=prev;
        for(int i=1;i<v.size();i++)
        {
           temp=new ListNode(v[i]);
           prev->next=temp;
           prev=temp;
        }
        temp->next=nullptr;
        return dummy->next;
    }
};