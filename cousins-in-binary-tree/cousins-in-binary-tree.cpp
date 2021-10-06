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
    int parentx=-1,parenty=-1;
    int height(TreeNode* root,int h,int value,int &parent)
    {
        int x=0,y=0;
        if(root==NULL)
        return 0;
        if(root->val==value)
        return h;
        parent=root->val;
        if(root->left)
        x=height(root->left,h+1,value,parent);
        if(x!=0)
        return x;
        parent=root->val;
        if(root->right)
        y=height(root->right,h+1,value,parent);
        return y;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x||root->val==y)
        return false;
        int parentx=-1,parenty=-1;
        int heightx=height(root,0,x,parentx);
        int heighty=height(root,0,y,parenty);
        return (heightx==heighty&&parentx!=parenty);
    }
};