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
    int ans=0;
    vector<int> fun(TreeNode* root,int d)
    {
        if(root==NULL)
        return {0};
        if(!root->left&&!root->right)
        {
            return {1};
        }
        vector<int> l,r;
        l=fun(root->left,d);
        r=fun(root->right,d);
        for(auto &x:l)
        {
            for(auto &y:r)
            {
                if(x&&y&&x+y<=d)
                {
                    ans++;
                }
            }
        }
        vector<int> ret;
        for(auto &x:l)
        {
            if(x&&x+1<d)
            {
                ret.push_back(x+1);
            }
        }
        for(auto &y:r)
        {
            if(y&&y+1<d)
            {
                ret.push_back(y+1);
            }
        }
        return ret;
    }
    int countPairs(TreeNode* root, int d) {
        fun(root,d);
        return ans;
    }
};