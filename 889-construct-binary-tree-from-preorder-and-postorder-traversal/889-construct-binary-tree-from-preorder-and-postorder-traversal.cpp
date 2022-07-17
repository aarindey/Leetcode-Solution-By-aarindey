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
    TreeNode* helper(vector<int>& pre,int psi,int pei,vector<int>& post,int ppsi,int ppei)
    {
        if(psi>pei)
        return NULL;
        TreeNode* root=new TreeNode(pre[psi]);
        if(psi==pei)
        return root;
        
        int idx=ppsi;
        while(post[idx]!=pre[psi+1])
        idx++;
        
        int len=idx-ppsi+1;
        root->left=helper(pre,psi+1,psi+len,post,ppsi,idx);
        root->right=helper(pre,psi+len+1,pei,post,idx+1,ppei);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return helper(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    }
};