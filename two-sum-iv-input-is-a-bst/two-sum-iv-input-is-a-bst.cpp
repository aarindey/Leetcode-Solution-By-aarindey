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
    bool findTarget(TreeNode* root, int k) {
      vector<int> vec;
      inorder(root,vec);
      return find(vec,k);  
    }
    bool find(vector<int> &v,int target)
    {
        int i=0,j=v.size()-1,sum;
        while(i<j)
        {
            sum=v[i]+v[j];
            if(sum==target)
            return true;
            else if(sum<target)
            {
                i++;
            }
            else 
            {
                j--;
            }
        }
        return false;
    }
};