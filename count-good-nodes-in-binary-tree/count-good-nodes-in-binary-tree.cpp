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
    void countGood(TreeNode* root,int &c,int maxi)
    {
        if(!root)
        return;
        maxi=max(maxi,root->val);
        if(root->val>=maxi)
        c++;
        countGood(root->left,c,maxi);
        countGood(root->right,c,maxi);
    }
    int goodNodes(TreeNode* root) {
        int c=0;
        countGood(root,c,INT_MIN);
        return c;
    }
};