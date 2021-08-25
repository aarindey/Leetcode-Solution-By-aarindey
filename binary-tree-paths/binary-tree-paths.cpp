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
    vector<string> ans;
    void dfs(TreeNode* root,string path)
    {
     if(root==NULL)
     return;
     if(root->left==NULL&root->right==NULL)
     {
         path+=to_string(root->val);
         ans.push_back(path);
         return;
     }
     else
     {
         path+=to_string(root->val)+"->";
     }
         dfs(root->left,path);
         dfs(root->right,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path="";
        dfs(root,path);
        return ans;
    }
};