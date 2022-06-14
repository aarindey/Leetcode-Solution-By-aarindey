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
    void invert(TreeNode* root)
    {
        //base case
        if(root==NULL)
        return;
        //recur
        if(root->left)
        invert(root->left);
        if(root->right)
        invert(root->right);
        //swapping nodes 
        TreeNode* r=root->right;
        TreeNode* l=root->left;
        root->left=r;
        root->right=l;
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};