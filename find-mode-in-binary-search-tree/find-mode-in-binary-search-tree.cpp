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
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(root==NULL)
        return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);    
    }   
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        for(int i:v)
        {
            mp[i]++;
            maxi=max(maxi,mp[i]);
        }
        vector<int> ans;
        for(auto pr:mp)
        {
            if(pr.second==maxi)
            ans.push_back(pr.first);
        }
        return ans;
    }
};