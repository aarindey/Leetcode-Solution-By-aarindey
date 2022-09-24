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
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int targetSum,int currSum,vector<int> &path)
    {
        if(root==NULL)
        return;    
        currSum+=root->val;
        path.push_back(root->val);
        if(targetSum==currSum&&root->left==NULL&&root->right==NULL)
        {
        ans.push_back(path);
        }   
        else 
        {    
        dfs(root->left,targetSum,currSum,path);
        dfs(root->right,targetSum,currSum,path);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root,targetSum,0,path);
        return ans;
    }
};