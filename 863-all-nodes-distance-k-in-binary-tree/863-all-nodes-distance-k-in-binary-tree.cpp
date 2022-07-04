/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //creating the parent map so that we can traverse backwards
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* ele=q.front();
            q.pop();
            if(ele->left)
            {
                parent[ele->left]=ele;
                q.push(ele->left);
            }
            if(ele->right)
            {
                parent[ele->right]=ele;
                q.push(ele->right);
            }
        }
        // bfs to find all nodes at a distance k from target
        q.push(target);
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        int dis=0;
        while(!q.empty())
        {
            int size=q.size();
            if(dis==k)
            break;
            while(size--)
            {
                TreeNode* ele=q.front();
                q.pop();
                if(ele->left&&!vis[ele->left])
                {
                    vis[ele->left]=true;
                    q.push(ele->left);
                }
                if(ele->right&&!vis[ele->right])
                {
                    vis[ele->right]=true;
                    q.push(ele->right);
                }
                if(parent.find(ele)!=parent.end()&&!vis[parent[ele]])
                {
                    vis[parent[ele]]=true;
                    q.push(parent[ele]);
                }
            }
            dis++;
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};