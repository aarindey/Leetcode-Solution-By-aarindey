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
    TreeNode* dfs(TreeNode* root,int &sum)
    {
        if(root==NULL)
        return NULL;
        dfs(root->right,sum);
        root->val+=sum;
        sum=root->val;
        dfs(root->left,sum);
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v;
        int sum=0;
        return dfs(root,sum); 
    }
};