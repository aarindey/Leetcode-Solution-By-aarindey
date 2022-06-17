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
    int count=0;
    int recurse(TreeNode* node)
    {
        if(node==NULL)
        {
            return 1;
        }
        int l=recurse(node->left);
        int r=recurse(node->right);
        if(l==-1||r==-1)
        {
            count++;
            return 0;
        }
        if(l==0||r==0)
        {
            return 1;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(recurse(root)==-1)
        {
            count++;
        }
        return count;
    }
};