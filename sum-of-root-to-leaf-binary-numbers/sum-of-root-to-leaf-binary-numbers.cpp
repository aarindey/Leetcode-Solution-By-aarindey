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
    int sum=0;
    string s="";
    void binaryToDecimal(string binary)
    {
        int sum1=0;
        for(int i=binary.length()-1;i>=0;i--)
        {
            sum1+=pow(2,binary.length()-1-i)*(binary[i]-'0');
        }
        sum+=sum1;
    }
    void helper(TreeNode* root)
    {
      if(root==NULL)
      return;  
      s+=to_string(root->val);  
      if(root->left==NULL&&root->right==NULL)
      {
      binaryToDecimal(s);
      }
          helper(root->left);
          helper(root->right);
        s.pop_back();
    }    
    int sumRootToLeaf(TreeNode* root) {
      helper(root);
      return sum;
    }
};