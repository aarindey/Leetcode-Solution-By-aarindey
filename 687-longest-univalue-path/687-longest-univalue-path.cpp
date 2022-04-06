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
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)
        return 0;
        int longestLength=0;
        dfs(root,longestLength);
        return longestLength;
    }
    int dfs(TreeNode* root,int& val)
    {
        int l=(root->left)?dfs(root->left,val):0;
        int r=(root->right)?dfs(root->right,val):0;
        if(root->left&&root->left->val==root->val)
        {
            l+=1;
        }
        else
        l=0;
        if(root->right&&root->right->val==root->val)
        {
            r+=1;
        }
        else
        r=0;
        val=max(val,l+r);
        return max(l,r);
    }
};