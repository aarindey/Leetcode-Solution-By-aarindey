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
    TreeNode* solve(TreeNode* &root,int val)
    {
        if(root==NULL)
        return root=new TreeNode(val);
        if(root->val>val)
        {
            root->left=solve(root->left,val);
        }
        else
        {
            root->right=solve(root->right,val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      TreeNode* root=NULL;
       for(auto ele:preorder)
        solve(root,ele);
        return root;
    }
};