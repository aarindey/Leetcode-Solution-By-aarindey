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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(!q.empty())
        {
            int size=q.size();
            v.clear();
            while(size--)
            {
                TreeNode* ele=q.front();
                v.push_back(ele->val);
                q.pop();
                if(ele->left)
                {
                    q.push(ele->left);
                }
                if(ele->right)
                {
                    q.push(ele->right);
                }
            }   
        }
        return v[0];
    }
};