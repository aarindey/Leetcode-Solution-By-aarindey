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
class BSTIterator {
private:
    vector<int> inorder;
    int i;
public:
    BSTIterator(TreeNode* root) {
        cons_inorder(root,inorder);
        i=-1;
    }
    void cons_inorder(TreeNode* root,vector<int> &inorder)
    {
       if(!root)
       return;
       cons_inorder(root->left,inorder);
       inorder.push_back(root->val);
       cons_inorder(root->right,inorder);
    }
    int next() {
       i++;
       return inorder[i];
    }
    
    bool hasNext() {
        return (i+1<inorder.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */