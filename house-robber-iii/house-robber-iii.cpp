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
    pair<int,int> helper(TreeNode* root)
    {
        if(root==NULL)
        return {0,0};
        pair<int,int> l,r;
        l=helper(root->left);
        r=helper(root->right);
        int con_root,not_con_root;
        pair<int,int> res;
        con_root=root->val+l.second+r.second;
        not_con_root=max(l.first,l.second)+max(r.first,r.second);
        res.first=con_root;
        res.second=not_con_root;
        return res;
    }
    int rob(TreeNode* root) {
        pair<int,int> ans= helper(root);
        return max(ans.first,ans.second);
    }
};