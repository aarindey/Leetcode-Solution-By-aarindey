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
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* temp=head;
        int count=0;
        int com=0;
        bool ok=true;
        while(temp)
        {
            int x=temp->val;
            if(find(nums.begin(),nums.end(),x)!=nums.end())
            {
                count++;
                if(ok)
                {
                com++;
                ok=false;
                }
            }
            else
            {
                count=0;
                ok=true;
            }
            temp=temp->next;
        }
        return com;
    }
};