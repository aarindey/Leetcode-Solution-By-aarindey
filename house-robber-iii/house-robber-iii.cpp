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
    unordered_map<TreeNode*,int> mp;
    int recurse(TreeNode* root)
    {
        if(!root)
        return 0;
        if(mp.count(root)>0)
        return mp[root];
        int ans_including_root=root->val;
        if(root->left!=NULL)
        {
            ans_including_root+=recurse(root->left->left)+recurse(root->left->right);
        }
        if(root->right!=NULL)
        {
             ans_including_root+=recurse(root->right->left)+recurse(root->right->right);
        }
        int ans_excluding_root=recurse(root->left)+recurse(root->right);
        mp[root]=max(ans_including_root,ans_excluding_root);
        return mp[root];
    }
    int rob(TreeNode* root) {
        return recurse(root);
    }
};