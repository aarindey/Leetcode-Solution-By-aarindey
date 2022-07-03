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
#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    int findNodeSum(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        int sum=root->val;
        int l=findNodeSum(root->left);
        int r=findNodeSum(root->right);
        sum+=(l+r);
        root->val=sum;
        return sum;
    }
    int maxProduct(TreeNode* root) {
        int parSum=findNodeSum(root);
        queue<TreeNode*> q;
        q.push(root);
        ll maxi=INT_MIN;
        while(!q.empty())
        {
            TreeNode* ele=q.front();
            q.pop();
            
            if(ele->left)
            {
                int lowerSum=ele->left->val;
                int restSum=parSum-lowerSum;
                maxi=max((ll)maxi,(ll)(restSum*(1ll)*lowerSum));
                q.push(ele->left);
            }
            if(ele->right)
            {
                int lowerSum=ele->right->val;
                int restSum=parSum-lowerSum;

                maxi=max((ll)maxi,(ll)(restSum*(1ll)*lowerSum));
                q.push(ele->right);
            }
        }
        return maxi%mod;
    }
};