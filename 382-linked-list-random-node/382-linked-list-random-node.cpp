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
private:
    ListNode* root;
public:
    Solution(ListNode* head) {
        root=head;
    }
    
    int getRandom() {
       int len=0;
       ListNode* temp=root;
       vector<int> v;
       while(temp)
       {
           len++;
           v.push_back(temp->val);
           temp=temp->next;
       }
       return v[rand()%len];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */