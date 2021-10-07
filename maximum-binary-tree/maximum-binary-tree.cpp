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
    int maxValIndex(vector<int> &v,int s,int e)
    {
        int maxVal=INT_MIN;
        int idx=-1;
        for(int i=s;i<=e;i++)
        {
            if(v[i]>maxVal)
            {
                maxVal=v[i];
                idx=i;
            }
        }
        return idx;
    }
    TreeNode* construct(vector<int>& nums,int start,int end)
    {
        if(start>end)
        return NULL;
        if(start==end)
        return new TreeNode(nums[start]);
        int rootValIdx=maxValIndex(nums,start,end);
        TreeNode* root=new TreeNode(nums[rootValIdx]);
        root->left=construct(nums,start,rootValIdx-1);
        root->right=construct(nums,rootValIdx+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=construct(nums,0,nums.size()-1);
        return root;
    }
};