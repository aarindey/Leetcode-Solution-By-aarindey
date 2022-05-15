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
    int deepestLeavesSum(TreeNode* root) {
  queue<TreeNode* > q;
    if(root==nullptr)
      return 1;
        q.push(root);
    int sum=0;
        int curr_sum;
        while(!q.empty())
    {
   size_t size=q.size();
         curr_sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                curr_sum+=curr->val;
                if(curr->left)
                  q.push(curr->left);
                 if(curr->right)
                   q.push(curr->right);
            }
                         sum=curr_sum;
            
    }
                         return sum;
    }
};