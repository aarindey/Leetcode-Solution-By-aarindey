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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for(auto list:lists)
        {
            while(list!=NULL)
            {
                v.push_back(list->val);
                list=list->next;
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        ListNode *ptr1=nullptr,*ptr2=nullptr;
        for(auto x:v)
        {
            ptr1=new ListNode(x,ptr2);
            ptr2=ptr1;
        }
        return ptr1;
    }
};