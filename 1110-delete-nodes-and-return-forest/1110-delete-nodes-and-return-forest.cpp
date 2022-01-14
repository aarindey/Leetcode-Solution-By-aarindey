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
    vector<TreeNode*> ans;
    set<int> st;
    TreeNode* helper(TreeNode* root,bool is_root)
    {
        if(!root)
        return NULL;
        bool deleted=st.find(root->val)!=st.end();
        if(!deleted&&is_root)
        {
            ans.push_back(root);
        }
        root->left=helper(root->left,deleted);
        root->right=helper(root->right,deleted);
        if(deleted)
        return NULL;
        
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i=0;i<to_delete.size();i++)
        {
            st.insert(to_delete[i]);
        }
        helper(root,true);
        return ans;
    }
};
    