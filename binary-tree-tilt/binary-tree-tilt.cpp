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
    int ans=0;
    int tiltsum(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        int leftSum=tiltsum(root->left);
        int rightSum=tiltsum(root->right);
        ans+=abs(leftSum-rightSum);
        return root->val+leftSum+rightSum;
    }
    int findTilt(TreeNode* root) {
        if(!root)
        return 0;
        tiltsum(root);
        return ans;
    }
};