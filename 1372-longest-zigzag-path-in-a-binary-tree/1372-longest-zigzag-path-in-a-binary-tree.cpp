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
class node{
    public:
    int leftSlope;
    int rightSlope;
    int maxVal;
    public: 
    node()
    {
        leftSlope=-1;
        rightSlope=-1;
        maxVal=0;
    }
};
class Solution {
public:
    node fun(TreeNode* root)
    {
        if(root==NULL)
        {
            node temp;
            return temp;
        }
        
        node left=fun(root->left);
        node right=fun(root->right);
        node ans;
        ans.maxVal=max({left.maxVal,right.maxVal,1+max(left.rightSlope,right.leftSlope)});
        ans.leftSlope=1+left.rightSlope;
        ans.rightSlope=1+right.leftSlope;
        return ans;
    }
    int longestZigZag(TreeNode* root) {
        return fun(root).maxVal;
    }
};