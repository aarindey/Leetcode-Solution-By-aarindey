class Solution {
public:
    
    vector<int> ans;
    bool ok=true;
    void giveAns(TreeNode* root,vector<int>& ar,int &i){
        if(!ok) return;
        if(!root) return;
        if(i>=ar.size()) return;
        if(root->val!=ar[i]){
            ok=false;
            return;
        }
        ++i;
        if(i>=ar.size()) return;
        if(root->left){
            if(root->right){
                if(root->left->val!=ar[i]){
                    if(root->right->val!=ar[i]){
                        ok=false;
                        return;
                    }
                    TreeNode *tmp=root->left;
                    root->left=root->right;
                    root->right=tmp;
                    ans.push_back(root->val);
                }
            }
            else{
                if(root->left->val!=ar[i]){
                    ok=false;
                    return;
                }
            }
        }
        else{
            if(root->right){
                if(root->right->val!=ar[i]){
                    ok=false;
                    return;
                }
            }
        }
        giveAns(root->left,ar,i);
        giveAns(root->right,ar,i);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& ar) {
        int i=0;
        giveAns(root,ar,i);
        if(!ok){
            ans.clear();
            ans.push_back(-1);
            return ans;
        }
        return ans;
    }
};