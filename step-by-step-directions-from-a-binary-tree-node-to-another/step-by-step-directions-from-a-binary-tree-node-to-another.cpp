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
   TreeNode* ancestor(TreeNode* root,int startValue,int destValue)
   {
       if(root==NULL)
       return NULL;
       if(root->val==startValue||root->val==destValue)
       return root;
       TreeNode* l=ancestor(root->left,startValue,destValue);
       TreeNode* r=ancestor(root->right,startValue,destValue);
       if(l!=NULL&&r!=NULL)
       return root;
       return l?l:r;
   }
    bool dfs(TreeNode* root,int f,string &temp)
    {
        if(root==NULL)
        return false;
        if(root->val==f)
        return true;
        temp+='L';
        bool t=dfs(root->left,f,temp);
        if(t)
        return true;
        temp.pop_back();
        temp+='R';
        t=dfs(root->right,f,temp);
        if(t)
        return true;
        temp.pop_back();
        
       return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
       TreeNode* lca=ancestor(root,startValue,destValue);
       string t1="",t2="";
       dfs(lca,startValue,t1);
       dfs(lca,destValue,t2);
        string ans="";
        int x=t1.size();
        while(x--)
        ans+='U';
        for(int i=0;i<t2.size();i++)
        ans+=t2[i];
        return ans;
    }
};