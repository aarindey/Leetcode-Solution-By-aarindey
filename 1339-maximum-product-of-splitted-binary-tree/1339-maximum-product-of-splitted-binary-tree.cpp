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
    ll ans=0;
    ll total;
    ll totalSum(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        ll l=totalSum(root->left);
        ll r=totalSum(root->right);
        return l+r+root->val;
    }
    ll calculateMaxi(TreeNode *root)
    {
        if(root==NULL)
        return 0;
        ll l=calculateMaxi(root->left);
        ll r=calculateMaxi(root->right);
        ll lowerSum=l+r+root->val;
        ans=max(ans,lowerSum*(1ll)*(total-lowerSum));
        return lowerSum;
    }
    int maxProduct(TreeNode* root) {
        total=totalSum(root);
        calculateMaxi(root);
        return ans%mod;
    }
};