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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> vec;
        if(n==1)
        vec.push_back(new TreeNode(0));
        else
        {
            for(int i=1;i<n;i+=2)
            {
                int l=i;
                int r=n-i-1;
                for(TreeNode* left_node:allPossibleFBT(l))
                {
                    for(TreeNode* right_node:allPossibleFBT(r))
                    {
                      TreeNode* root=new TreeNode(0);
                      root->left=left_node;
                      root->right=right_node;
                      vec.push_back(root);
                    }
                }
            }
        }
        return vec;
    }
};