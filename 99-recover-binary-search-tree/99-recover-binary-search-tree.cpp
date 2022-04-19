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
    TreeNode *first=NULL,*second=NULL;
    TreeNode* prev=new TreeNode(INT_MIN);
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(root==NULL)
        return;
        inorder(root->left,v);
        if(first==NULL&&prev->val>root->val)
        first=prev;
        if(first!=NULL&&prev->val>root->val)
        second=root;
        prev=root;
        inorder(root->right,v);
    }    
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int temp=second->val;
        second->val=first->val;
        first->val=temp;
    }
};