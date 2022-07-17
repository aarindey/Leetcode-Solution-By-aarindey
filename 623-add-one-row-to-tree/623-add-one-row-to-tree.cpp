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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        q.push(root);
        if(depth==1)
        {
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        while(--depth>1)
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* ele=q.front();
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
        
        while(!q.empty())
        {
            TreeNode* ele=q.front();
            q.pop();
            TreeNode* l=ele->left;
            TreeNode* r=ele->right;
            TreeNode* nodel=new TreeNode(val);
            TreeNode* noder=new TreeNode(val);
            ele->left=nodel;
            nodel->left=l;
            ele->right=noder;
            noder->right=r;
        }
        return root;
    }
};