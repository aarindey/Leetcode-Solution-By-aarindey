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
    int height(TreeNode* root)
    {
        if(!root)
        return 0;
        return 1+max(height(root->left),height(root->right));
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        while(true)
        {
            int left1=height(root->left);
            int right1=height(root->right);
            if(left1==right1)
            return root;
            if(left1>right1)
            {
                root=root->left;
            }
            else
            root=root->right;
        }
    }
};