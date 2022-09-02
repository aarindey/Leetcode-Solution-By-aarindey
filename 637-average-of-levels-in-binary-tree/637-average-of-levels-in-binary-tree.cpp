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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum;
        vector<int> size;
        dfs(root,0,sum,size);
        for(int i=0;i<sum.size();i++){
            sum[i] /= size[i];
        }
        return sum;
    }
    void dfs(TreeNode* root,int level,vector<double>& sum, vector<int>& size){
        if(root){
            if(level >= sum.size()){
                sum.push_back(0);
                size.push_back(0);
            }
            sum[level] += root->val;
            size[level] += 1;
            dfs(root->left,level+1,sum,size);
            dfs(root->right,level+1,sum,size);
        }
    }
};