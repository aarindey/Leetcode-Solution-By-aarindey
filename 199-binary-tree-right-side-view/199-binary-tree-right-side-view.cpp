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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
        return ans;
        map<int,int> mp;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                TreeNode* ele=q.front();
                q.pop();
                mp[level]=ele->val;
                if(ele->left)
                {
                    q.push(ele->left);
                }
                if(ele->right)
                {
                    q.push(ele->right);
                }
            }
            level++;
        }
        for(auto &pr:mp)
        {
            ans.push_back(pr.second);
        }
        return ans;
    }
};