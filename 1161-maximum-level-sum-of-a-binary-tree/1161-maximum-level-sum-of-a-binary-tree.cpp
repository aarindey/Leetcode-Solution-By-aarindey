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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        int ans=1,maxSum=root->val;
        while(!q.empty())
        {
            level++;
            int sum=0;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* ele=q.front();
                q.pop();
                sum+=ele->val;
                if(ele->left)
                q.push(ele->left);
                if(ele->right)
                q.push(ele->right);
            }
            if(sum>maxSum)
            {
                maxSum=sum;
                ans=level;
            }
        }
        return ans;
    }
};