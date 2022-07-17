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
    string postorder(TreeNode* root,map<string,int> &mp,vector<TreeNode*> &ans)
    {
        if(root==NULL)
        return "";
        
        string left=postorder(root->left,mp,ans);
        string right=postorder(root->right,mp,ans);
        
        string key=left+"#"+right+"#"+to_string(root->val);
        if(mp[key]==1)
        {
            ans.push_back(root);
            mp[key]++;
        }
        else
        mp[key]++;
        return key;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int> mp;
        vector<TreeNode*> ans;
        postorder(root,mp,ans);
        return ans;
    }
};