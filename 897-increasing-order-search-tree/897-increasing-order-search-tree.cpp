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
    TreeNode* curr;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        return;
        if(root->left)
        inorder(root->left);
        root->left=NULL;
        curr->right=root;
        curr=root;
        if(root->right)
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
    if(root==NULL)
    return NULL;
     TreeNode* dummy=new TreeNode(0);
     curr=dummy;
     inorder(root);
     return dummy->right;
    }
};
