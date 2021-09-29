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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp=head;
        if(k==0)
        return ans;
        if(k==1)
        {
            ans.push_back(head);
            return ans;
        }
        if(head==NULL&&k>0)
        {
            temp=NULL;
            while(k--)
            {
                ans.push_back(temp);
            }
            return ans;
        }
        int l=0;
        while(temp!=NULL)
        {
            l++;
            temp=temp->next;
        }
        
        int len=l/k;
        int distribute=l%k;
        ListNode *prev=NULL,*node=head;
        int i=0;
        while(node!=NULL and i<k){
            ans.push_back(node);
            for(int j=0;j<len+(distribute>0?1:0);j++)
            {
                prev=node;
                node=node->next;
            }
            prev->next=NULL;
            i++;
            distribute--;
        }
        while(l<k)
        {
            ans.push_back(NULL);
            l++;
        }
        return ans;
    }
};