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
    int subtreesum(TreeNode* node)
    {
        if(node==NULL)
        return 0;
        int sum=node->val;
        sum+=subtreesum(node->left);
        sum+=subtreesum(node->right);
        return sum;
    }
    void sumtilt(TreeNode* root,int &sum)
    {
        if(!root->left&&!root->right)
        {
            return;
        }
        else if(root->left==NULL&&root->right!=NULL)
        {
            sum+=abs(subtreesum(root->right));
            sumtilt(root->right,sum);
        }
        else if(root->left!=NULL&&root->right==NULL)
        {
            sum+=abs(subtreesum(root->left));
            sumtilt(root->left,sum);
        }
        else
        {
            sum+=abs(subtreesum(root->left)-subtreesum(root->right));
            sumtilt(root->left,sum);
            sumtilt(root->right,sum);
        }
    }
    int findTilt(TreeNode* root) {
      int sum=0;
      if(root==NULL)
        return 0;
      sumtilt(root,sum);
      return sum;
    }
};