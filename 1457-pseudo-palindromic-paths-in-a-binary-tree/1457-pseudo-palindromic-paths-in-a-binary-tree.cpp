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
    map<int,int> mp;
    bool check()
    {
        int odd=0;
        int even=0;
        for(auto &pr:mp)
        {
            //cout<<pr.first<<" "<<pr.second<<endl;
            if(pr.second&1)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        if(odd==0||odd==1)
        return true;
        
        return false;
    }
    int dfs(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(!root->left&&!root->right)
        {
            if(check())
            {
                return 1;
            }
            else
            return 0;
        }
        int l=0,r=0;
        if(root->left)
        {
            mp[root->left->val]++;
            l+=dfs(root->left);
            mp[root->left->val]--;
        }
        if(root->right)
        {
            mp[root->right->val]++;
            r+=dfs(root->right);
            mp[root->right->val]--;
        }
        return l+r;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        mp[root->val]++;
        return dfs(root);
    }
};