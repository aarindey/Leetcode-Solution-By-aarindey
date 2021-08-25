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
    int sum=0;
    bool last_left;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
         return;
        
        if(last_left&&root->left==NULL&&root->right==NULL)
        {
            sum+=root->val;
        }   
        last_left=false;
        dfs(root->right);
        last_left=true;
        dfs(root->left);
    }    
    int sumOfLeftLeaves(TreeNode* root) {
       
      dfs(root);
        return sum;
    }
};