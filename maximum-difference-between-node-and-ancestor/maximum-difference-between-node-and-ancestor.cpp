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
    int diff=0;
    void helper(TreeNode* root,int maxi,int mini)
    {
        if(!root)
        return;
        int res=max(abs(maxi-root->val),abs(mini-root->val));
        diff=max(diff,res);
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        helper(root->left,maxi,mini);
        helper(root->right,maxi,mini);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
        return 0;
        helper(root,root->val,root->val);
        return diff; 
    }
};