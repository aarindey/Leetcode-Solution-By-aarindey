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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructBST(vector<int> &v,int s,int e)
    {
        if(s>e)
        return NULL;
        
        int mid=(s+e)/2;
        int rootData=v[mid];
        TreeNode* root=new TreeNode(rootData);
        root->left=constructBST(v,s,mid-1);
        root->right=constructBST(v,mid+1,e);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> sortedArray;
        while(head)
        {
            sortedArray.push_back(head->val);
            head=head->next;
        }
        return constructBST(sortedArray,0,sortedArray.size()-1);
    }
};