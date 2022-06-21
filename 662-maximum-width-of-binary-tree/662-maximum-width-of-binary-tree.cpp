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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll ans=INT_MIN;
        while(!q.empty())
        {
            ll size=q.size();
            ll minn=q.front().second;
            ll first,last;
            for(int i=0;i<size;i++)
            {
                TreeNode* ele=q.front().first;
                ll val=q.front().second-minn;
                if(i==0)
                {
                    first=val;
                }
                if(i==size-1)
                {
                    last=val;
                }
                q.pop();
                if(ele->left)
                {
                    q.push({ele->left,2*val+1});
                }
                if(ele->right)
                {
                    q.push({ele->right,2*val+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return (int)ans;
    }
};