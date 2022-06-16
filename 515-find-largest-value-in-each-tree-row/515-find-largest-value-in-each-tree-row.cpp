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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        int maxi;
        if(root==NULL)
        return ans;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            maxi=INT_MIN;
            for(int i=0;i<sz;i++)
            {
                TreeNode* ele=q.front();
                q.pop();
                if(ele->val>maxi)
                {
                    maxi=ele->val;
                }
                if(ele->left)
                {
                    q.push(ele->left);
                }
                if(ele->right)
                {
                    q.push(ele->right);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};